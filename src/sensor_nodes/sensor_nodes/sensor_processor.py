#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_interfaces.msg import BatteryStatus, LidarScan, Odometry, SensorFusion
import threading
import time

class SensorProcessor(Node):
    def __init__(self):
        super().__init__('sensor_processor')
        # publishers
        self.pub_fusion = self.create_publisher(SensorFusion, '/sensor_fusion', 10)

        # subscribers
        self.sub_lidar = self.create_subscription(LidarScan, '/lidar_scan', self.lidar_cb, 10)
        self.sub_odom = self.create_subscription(Odometry, '/motor_odometry', self.odom_cb, 10)
        # subscribe to battery topic even if not available yet
        self.sub_battery = self.create_subscription(BatteryStatus, '/battery_level', self.battery_cb, 10)

        # last messages
        self.last_battery = None
        self.last_lidar = None
        self.last_odom = None

        # temporary internal battery simulation (used only while real battery node isn't available)
        self.mock_battery_enabled = True
        self._mock_level = 95.0
        self._mock_is_charging = False

        # timers
        self.create_timer(1.0, self.fusion_timer)  # fuse/publish at 1 Hz
        self.create_timer(2.0, self.mock_battery_timer)  # update mock battery every 2s

        self.get_logger().info('🎯 Sensor Processor started - subscribing to /lidar_scan, /motor_odometry, /battery_level')

    #
    # Callbacks for incoming real topics
    #
    def battery_cb(self, msg: BatteryStatus):
        # If a real battery message arrives, disable mock mode
        if self.mock_battery_enabled:
            self.get_logger().info('🔌 Real battery topic received — switching off mock battery.')
            self.mock_battery_enabled = False
        self.last_battery = msg

    def lidar_cb(self, msg: LidarScan):
        self.last_lidar = msg

    def odom_cb(self, msg: Odometry):
        self.last_odom = msg

    #
    # Mock battery (temporary) — only if no real data is coming
    #
    def mock_battery_timer(self):
        if not self.mock_battery_enabled:
            return

        # simulate battery drain: faster when moving
        moving = False
        if self.last_odom and abs(self.last_odom.linear_velocity) > 0.05:
            moving = True

        if moving:
            self._mock_level -= 0.5  # drain when moving
        elif self._mock_is_charging:
            self._mock_level += 2.0  # charge faster when charging
        else:
            self._mock_level -= 0.1  # slow idle drain

        # clamp
        self._mock_level = max(0.0, min(100.0, self._mock_level))

        # create a BatteryStatus message and store it as last_battery (so fusion uses it)
        b = BatteryStatus()
        b.level = float(self._mock_level)
        if b.level > 70:
            b.health_status = 'Good'
        elif b.level > 30:
            b.health_status = 'Warning'
        else:
            b.health_status = 'Critical'
        b.is_charging = bool(self._mock_is_charging)
        b.voltage = 3.7 + (b.level / 100.0) * 0.8  # simple simulated voltage

        self.last_battery = b
        self.get_logger().debug(f'[MOCK BAT] level={b.level:.1f} health={b.health_status}')

    #
    # Fusion & publish
    #
    def fusion_timer(self):
        # require at least lidar and odom to produce meaningful fusion. battery can be mock.
        if self.last_lidar is None:
            self.get_logger().warn_once = getattr(self, 'warn_once', False)
            if not self.get_logger().warn_once:
                self.get_logger().warn('No LIDAR data yet — waiting for /lidar_scan')
                self.get_logger().warn_once = True
            return
        if self.last_odom is None:
            self.get_logger().warn_once_odom = getattr(self, 'warn_once_odom', False)
            if not self.get_logger().warn_once_odom:
                self.get_logger().warn('No Odometry data yet — waiting for /motor_odometry')
                self.get_logger().warn_once_odom = True
            return
        if self.last_battery is None:
            # shouldn't happen because mock sets last_battery, but keep check
            self.get_logger().warn('No battery data yet (mock not initialized). Publishing with battery=100')
            # create minimal fake
            from delivery_interfaces.msg import BatteryStatus as BS
            b = BS()
            b.level = 100.0
            b.health_status = 'Good'
            b.is_charging = False
            b.voltage = 4.0
            self.last_battery = b

        # assemble SensorFusion
        sf = SensorFusion()
        sf.battery_level = float(self.last_battery.level)
        sf.obstacle_count = int(self.last_lidar.obstacle_count)
        sf.position_x = float(self.last_odom.x)
        sf.position_y = float(self.last_odom.y)

        # apply SIMPLE rules (Option A)
        # If battery < 20% OR obstacles > 2 -> DANGER
        # Else if battery < 40% OR obstacles > 0 -> CAUTION
        # Else -> SAFE
        if sf.battery_level < 20.0 or sf.obstacle_count > 2:
            sf.overall_status = 'DANGER'
        elif sf.battery_level < 40.0 or sf.obstacle_count > 0:
            sf.overall_status = 'CAUTION'
        else:
            sf.overall_status = 'SAFE'

        self.pub_fusion.publish(sf)
        self.get_logger().info(f'🔄 Sensor Fusion published | battery={sf.battery_level:.1f}% obstacles={sf.obstacle_count} pos=({sf.position_x:.2f},{sf.position_y:.2f}) status={sf.overall_status}')

def main(args=None):
    rclpy.init(args=args)
    node = SensorProcessor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
