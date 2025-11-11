#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_interfaces.msg import BatteryStatus, LidarScan, Odometry, SensorFusion

class SensorProcessor(Node):
    def __init__(self):
        super().__init__('sensor_processor')
        # publishers
        self.pub_fusion = self.create_publisher(SensorFusion, '/sensor_fusion', 10)

        # subscribers
        self.sub_lidar = self.create_subscription(LidarScan, '/lidar_scan', self.lidar_cb, 10)
        self.sub_odom = self.create_subscription(Odometry, '/motor_odometry', self.odom_cb, 10)
        self.sub_battery = self.create_subscription(BatteryStatus, '/battery_level', self.battery_cb, 10)

        # last messages
        self.last_battery = None
        self.last_lidar = None
        self.last_odom = None

        # timer
        self.create_timer(1.0, self.fusion_timer)  # fuse/publish at 1 Hz

        self.get_logger().info('🎯 Sensor Processor started - subscribing to /lidar_scan, /motor_odometry, /battery_level')

    #
    # Callbacks for incoming topics
    #
    def battery_cb(self, msg: BatteryStatus):
        self.last_battery = msg

    def lidar_cb(self, msg: LidarScan):
        self.last_lidar = msg

    def odom_cb(self, msg: Odometry):
        self.last_odom = msg

    #
    # Fusion & publish
    #
    def fusion_timer(self):
        # Check if we have all required data
        if self.last_lidar is None:
            self.get_logger().warn('No LIDAR data yet — waiting for /lidar_scan', throttle_duration_sec=5.0)
            return
        if self.last_odom is None:
            self.get_logger().warn('No Odometry data yet — waiting for /motor_odometry', throttle_duration_sec=5.0)
            return
        if self.last_battery is None:
            self.get_logger().warn('No Battery data yet — waiting for /battery_level', throttle_duration_sec=5.0)
            return

        # Assemble SensorFusion
        sf = SensorFusion()
        sf.battery_level = float(self.last_battery.level)
        sf.obstacle_count = int(self.last_lidar.obstacle_count)
        sf.position_x = float(self.last_odom.x)
        sf.position_y = float(self.last_odom.y)

        # Apply simple safety rules:
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
        self.get_logger().info(
            f'🔄 Fusion | battery={sf.battery_level:.1f}% obstacles={sf.obstacle_count} '
            f'pos=({sf.position_x:.2f},{sf.position_y:.2f}) status={sf.overall_status}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = SensorProcessor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
