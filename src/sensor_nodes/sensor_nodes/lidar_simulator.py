#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import random
import math
from delivery_interfaces.msg import LidarScan

class LidarSimulator(Node):
    def __init__(self):
        super().__init__('lidar_simulator')
        self.pub = self.create_publisher(LidarScan, '/lidar_scan', 10)
        self.timer = self.create_timer(0.2, self.timer_callback)  # 5 Hz
        self.get_logger().info('🔭 Lidar simulator started (360° scan)')

    def timer_callback(self):
        msg = LidarScan()
        # 360 sample points (one per degree)
        samples = 360
        # base distances around 3.0m with noise
        base = 3.0
        distances = []
        angles = []
        # create a few obstacles randomly (simulate nearer distances in sectors)
        obstacle_sectors = []
        if random.random() < 0.4:  # 40% chance some obstacles appear
            n_obs = random.randint(1, 4)
            for _ in range(n_obs):
                # a sector center and width
                center = random.randint(0, samples-1)
                width = random.randint(3, 20)
                obstacle_sectors.append((center, width))

        for i in range(samples):
            # angle in degrees
            angles.append(float(i))
            d = random.uniform(base - 0.6, base + 0.6)
            # if i falls in an obstacle sector, make it close
            for center, width in obstacle_sectors:
                # handle wrap-around
                dist_index = min(abs(i - center), samples - abs(i - center))
                if dist_index <= width:
                    d = random.uniform(0.2, 1.2)  # obstacle close
                    break
            distances.append(float(d))

        # count obstacles by thresholding contiguous close readings
        obstacle_count = 0
        threshold = 1.0
        in_obstacle = False
        for dd in distances:
            if dd < threshold and not in_obstacle:
                obstacle_count += 1
                in_obstacle = True
            elif dd >= threshold and in_obstacle:
                in_obstacle = False

        msg.distances = distances
        msg.angles = angles
        msg.obstacle_count = int(obstacle_count)

        self.pub.publish(msg)
        self.get_logger().debug(f'LIDAR published: obstacles={msg.obstacle_count}')

def main(args=None):
    rclpy.init(args=args)
    node = LidarSimulator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
