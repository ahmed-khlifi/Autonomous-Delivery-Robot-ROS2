import math
import threading
from typing import Optional

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, GoalResponse, CancelResponse

from delivery_interfaces.action import NavigateTo
from delivery_interfaces.msg import BatteryStatus  # from your interfaces

class MissionPlanner(Node):
    """
    Mission Planner:
    - Chooses/accepts a destination
    - Sends NavigateTo goal to /navigate_to
    - Streams feedback (progress %, ETA, status)
    - Cancels if battery low or emergency flag set
    - Summarizes result
    """

    def __init__(self):
        super().__init__('mission_planner')

        # --- Parameters (you can override via YAML/CLI) ---
        self.declare_parameter('destination.name', 'Office')
        self.declare_parameter('destination.x', 8.0)
        self.declare_parameter('destination.y', 6.0)

        self.declare_parameter('battery_low_threshold', 20.0)  # %
        self.declare_parameter('auto_cancel_on_low_battery', True)

        # --- State ---
        self._current_goal_handle = None
        self._low_battery_seen = False
        self._lock = threading.Lock()

        # --- Subscribers (optional but recommended) ---
        self.create_subscription(BatteryStatus, '/battery_level',
                                 self._on_battery, 10)

        # --- Action Client ---
        self._nav_client = ActionClient(self, NavigateTo, '/navigate_to')

        self.get_logger().info('🚀 Mission Planner started')

        # kick off a mission automatically (or expose a service to trigger)
        self._start_initial_mission()

    # ========= Battery handling =========
    def _on_battery(self, msg: BatteryStatus):
        thr = float(self.get_parameter('battery_low_threshold').value)
        auto_cancel = bool(self.get_parameter('auto_cancel_on_low_battery').value)

        if msg.percentage < thr and auto_cancel:
            with self._lock:
                if not self._low_battery_seen:
                    self._low_battery_seen = True
                    self.get_logger().warn(
                        f'🔋 Battery low ({msg.percentage:.1f}%). Cancelling current mission…'
                    )
                    if self._current_goal_handle is not None:
                        self._cancel_goal_async()

    # ========= Mission flow =========
    def _start_initial_mission(self):
        # Read params
        name = self.get_parameter('destination.name').value
        x = float(self.get_parameter('destination.x').value)
        y = float(self.get_parameter('destination.y').value)

        # Announce
        self.get_logger().info(
            f'📦 New delivery mission: Package#123 → {name} ({x:.1f}, {y:.1f})'
        )

        # Wait for server (non-blocking spin)
        self.get_logger().info('⏳ Waiting for /navigate_to action server…')
        self._nav_client.wait_for_server()
        self.get_logger().info('✅ /navigate_to action server is up')

        # Build and send goal
        goal_msg = NavigateTo.Goal()
        goal_msg.target_x = x
        goal_msg.target_y = y
        goal_msg.location_name = name

        send_goal_future = self._nav_client.send_goal_async(
            goal_msg,
            feedback_callback=self._feedback_callback
        )
        send_goal_future.add_done_callback(self._goal_response_callback)

    def _goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('❌ Goal rejected by navigation controller')
            return

        self.get_logger().info('🟢 Goal accepted. Mission in progress…')
        self._current_goal_handle = goal_handle

        # Request result
        get_result_future = goal_handle.get_result_async()
        get_result_future.add_done_callback(self._result_callback)

    def _feedback_callback(self, feedback_msg):
        fb = feedback_msg.feedback
        # fb.progress_percent, fb.eta_seconds, fb.status
        self.get_logger().info(
            f'📡 Mission Progress: {fb.progress_percent:.1f}% | '
            f'ETA ~{fb.eta_seconds:.1f}s | {fb.status}'
        )

    def _result_callback(self, future):
        result = future.result().result
        reached = result.reached
        msg = result.message

        if reached:
            self.get_logger().info(f'🏁 Arrived at destination. {msg}')
            self.get_logger().info('📬 Delivery completed!')
        else:
            self.get_logger().warn(f'⚠️ Mission ended without arrival: {msg}')

        # Print a one-line mission summary
        self._print_summary(reached, msg)

        with self._lock:
            self._current_goal_handle = None
            self._low_battery_seen = False

    # ========= Cancel path =========
    def _cancel_goal_async(self):
        if self._current_goal_handle is None:
            return
        cancel_future = self._current_goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self._cancel_done)

    def _cancel_done(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().warn('🟡 Mission cancelled successfully.')
        else:
            self.get_logger().warn('⚠️ Mission could not be cancelled (maybe already finished).')

    # ========= Helpers =========
    def _print_summary(self, success: bool, message: str):
        name = self.get_parameter('destination.name').value
        x = float(self.get_parameter('destination.x').value)
        y = float(self.get_parameter('destination.y').value)

        status = 'SUCCESS' if success else 'FAILED'
        self.get_logger().info(
            f'🧾 Mission Summary → Dest: {name} ({x:.1f},{y:.1f}) | Status: {status} | Note: {message}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = MissionPlanner()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
