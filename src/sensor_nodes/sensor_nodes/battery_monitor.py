#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_interfaces.msg import BatteryStatus
import random

class BatteryMonitor(Node):
    def __init__(self):
        super().__init__('battery_monitor')
        self.publisher_ = self.create_publisher(BatteryStatus, '/battery_level', 10)
        self.battery_level = 100.0
        self.is_charging = False
        self.robot_moving = False
        self.timer = self.create_timer(2.0, self.publish_battery_status)
        self.get_logger().info("🔋 Battery Monitor started")

    def publish_battery_status(self):
        # Simulate battery drain or charge
        if self.robot_moving:
            self.battery_level -= 0.5
        elif self.is_charging:
            self.battery_level += 2.0
        else:
            self.battery_level -= 0.1

        # Keep within 0-100%
        self.battery_level = max(0.0, min(100.0, self.battery_level))

        # Determine health
        if self.battery_level > 70:
            health = "Good"
        elif self.battery_level > 30:
            health = "Warning"
        else:
            health = "Critical"

        # Fake voltage for simulation
        voltage = round(random.uniform(11.0, 12.6), 2)

        msg = BatteryStatus()
        msg.level = float(self.battery_level)
        msg.health_status = health
        msg.is_charging = self.is_charging
        msg.voltage = voltage

        self.publisher_.publish(msg)
        self.get_logger().info(f"📊 Battery Level: {msg.level:.1f}% | Health: {health}")

def main(args=None):
    rclpy.init(args=args)
    node = BatteryMonitor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
