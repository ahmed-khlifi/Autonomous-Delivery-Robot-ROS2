from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='mission_nodes',
            executable='mission_planner',
            name='mission_planner',
            output='screen',
            parameters=['/opt/ros/params/does-not-exist.yaml',  # ignored if missing
                        # local params file
                        {'destination.name': 'Reception',
                         'destination.x': 5.0,
                         'destination.y': 3.0,
                         'battery_low_threshold': 20.0,
                         'auto_cancel_on_low_battery': True}]
        )
    ])
parameters=['/opt/ros/params/does-not-exist.yaml',
            LaunchConfiguration('params_file', default=[ThisPackageShare, '/params/mission_planner.yaml'])]
