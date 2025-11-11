#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import random

from robot_interfaces.srv import EmergencyStop, SystemDiagnostic, GetRobotInfo


class CommandHandler(Node):
    def __init__(self):
        super().__init__('command_handler')

        # Create ROS 2 services
        self.create_service(EmergencyStop, '/emergency_stop', self.handle_emergency_stop)
        self.create_service(SystemDiagnostic, '/system_diagnostic', self.handle_system_diagnostic)
        self.create_service(GetRobotInfo, '/get_robot_info', self.handle_get_robot_info)

        self.get_logger().info('CommandHandler node started!')

    # -----------------------------
    # Emergency Stop Service
    # -----------------------------
    def handle_emergency_stop(self, request, response):
        if request.emergency:
            # Immediate actions (simulated)
            self.get_logger().info("Emergency stop activated!")
            # TODO: implement stop_all_motors, cancel_all_actions, publish_stop_signal
            response.success = True
            response.message = "Emergency stop activated - All systems halted"
        else:
            response.success = False
            response.message = "No emergency condition specified"
        return response

    # -----------------------------
    # System Diagnostic Service
    # -----------------------------
    def handle_system_diagnostic(self, request, response):
        components = ["battery", "motors", "sensors", "navigation"]
        statuses = [random.choice(["OK", "WARNING", "ERROR"]) for _ in components]

        response.system_ok = all(s == "OK" for s in statuses)
        response.status_message = "Full report generated" if request.full_report else "Partial report"
        response.components = components
        response.statuses = statuses
        response.battery_level = random.uniform(20.0, 100.0)  # float32
        response.error_count = sum(1 for s in statuses if s != "OK")  # int32

        return response

    # -----------------------------
    # Get Robot Info Service
    # -----------------------------
    def handle_get_robot_info(self, request, response):
        response.robot_state = random.choice(["IDLE", "NAVIGATING", "DELIVERING", "CHARGING", "ERROR", "RETURNING_TO_CHARGE"])
        response.position_x = random.uniform(0.0, 100.0)
        response.position_y = random.uniform(0.0, 100.0)
        response.battery_level = random.uniform(20.0, 100.0)
        response.current_mission = random.choice(["Delivering package", "Returning to charge", "Idle"])
        response.active_topics = ["/emergency_stop", "/system_diagnostic", "/get_robot_info"]

        return response


def main(args=None):
    rclpy.init(args=args)
    node = CommandHandler()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

