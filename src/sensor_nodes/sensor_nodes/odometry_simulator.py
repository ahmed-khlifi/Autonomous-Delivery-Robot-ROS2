#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import math
import time
from delivery_interfaces.msg import Odometry

class OdometrySimulator(Node):
    def __init__(self):
        super().__init__('odometry_simulator')
        self.pub = self.create_publisher(Odometry, '/motor_odometry', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)  # 10 Hz
        # Waypoints (x,y,theta) - you can expand this list
        self.waypoints = [
            (0.0, 0.0, 0.0),
            (2.0, 0.0, 0.0),
            (2.0, 2.0, math.pi/2),
            (0.0, 2.0, math.pi),
            (0.0, 0.0, -math.pi/2)
        ]
        self.current_index = 0
        self.x, self.y, self.theta = self.waypoints[0]
        self.target = self.waypoints[1]
        self.last_time = time.time()
        self.get_logger().info('🧭 Odometry simulator started (waypoints)')

    def timer_callback(self):
        now = time.time()
        dt = max(1e-6, now - self.last_time)
        self.last_time = now

        tx, ty, ttheta = self.target
        dx = tx - self.x
        dy = ty - self.y
        distance = math.hypot(dx, dy)
        # simple proportional linear speed toward target
        max_speed = 0.3  # m/s
        if distance > 0.01:
            step = min(max_speed * dt, distance)
            self.x += dx / distance * step
            self.y += dy / distance * step
            linear_velocity = step / dt
        else:
            linear_velocity = 0.0

        # orientation: rotate toward ttheta
        dtheta = (ttheta - self.theta + math.pi) % (2*math.pi) - math.pi
        max_angular = 0.6  # rad/s
        if abs(dtheta) > 0.02:
            rstep = max(-max_angular*dt, min(max_angular*dt, dtheta))
            self.theta += rstep
            angular_velocity = rstep / dt
        else:
            angular_velocity = 0.0

        # if close to target, advance to next waypoint
        if distance < 0.03 and abs(dtheta) < 0.03:
            self.current_index = (self.current_index + 1) % len(self.waypoints)
            self.target = self.waypoints[(self.current_index + 1) % len(self.waypoints)]

        msg = Odometry()
        msg.x = float(self.x)
        msg.y = float(self.y)
        msg.theta = float(self.theta)
        msg.linear_velocity = float(linear_velocity)
        msg.angular_velocity = float(angular_velocity)

        self.pub.publish(msg)
        self.get_logger().debug(f'ODOM published: x={msg.x:.2f} y={msg.y:.2f} v={msg.linear_velocity:.2f}')

def main(args=None):
    rclpy.init(args=args)
    node = OdometrySimulator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
