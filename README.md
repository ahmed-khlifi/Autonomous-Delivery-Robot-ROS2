
#### Sequence diagram for mission planning and battery-based cancellation

```mermaid
sequenceDiagram
actor User
participant MissionPlanner
participant "ActionServer(/navigate_to)"
participant "BatteryMonitor"
User->>MissionPlanner: Start mission
MissionPlanner->>"ActionServer(/navigate_to)": Send NavigateTo goal
"BatteryMonitor"->>MissionPlanner: Publish BatteryStatus
MissionPlanner->>MissionPlanner: Check battery threshold
alt Battery low and auto_cancel enabled
  MissionPlanner->>"ActionServer(/navigate_to)": Cancel goal
end
"ActionServer(/navigate_to)"->>MissionPlanner: Send feedback/result
MissionPlanner->>User: Mission summary
```

#### ER diagram for new delivery_interfaces and robot_interfaces services/messages

```mermaid
erDiagram
BATTERY_STATUS {
  float level
  string health_status
  bool is_charging
  float voltage
}
LIDAR_SCAN {
  float[] distances
  float[] angles
  int obstacle_count
}
ODOMETRY {
  float x
  float y
  float theta
  float linear_velocity
  float angular_velocity
}
SENSOR_FUSION {
  float battery_level
  int obstacle_count
  float position_x
  float position_y
  string overall_status
}
EMERGENCY_STOP {
  bool emergency
  bool success
  string message
}
SYSTEM_DIAGNOSTIC {
  bool full_report
  bool system_ok
  string status_message
  string[] components
  string[] statuses
  float battery_level
  int error_count
}
GET_ROBOT_INFO {
  string robot_state
  float position_x
  float position_y
  float battery_level
  string current_mission
  string[] active_topics
}
BATTERY_STATUS ||--o{ SENSOR_FUSION : provides
LIDAR_SCAN ||--o{ SENSOR_FUSION : provides
ODOMETRY ||--o{ SENSOR_FUSION : provides
```

#### Class diagram for new and updated ROS2 nodes

```mermaid
classDiagram
class BatteryMonitor {
  +float battery_level
  +bool is_charging
  +bool robot_moving
  +publish_battery_status()
}
class LidarSimulator {
  +create_publisher(LidarScan)
  +timer_callback()
}
class OdometrySimulator {
  +float x
  +float y
  +float theta
  +timer_callback()
}
class SensorProcessor {
  +SensorFusion pub_fusion
  +LidarScan sub_lidar
  +Odometry sub_odom
  +BatteryStatus sub_battery
  +fusion_timer()
  +mock_battery_timer()
}
class MissionPlanner {
  +ActionClient _nav_client
  +BatteryStatus sub_battery
  +_start_initial_mission()
  +_goal_response_callback()
  +_feedback_callback()
  +_result_callback()
  +_cancel_goal_async()
}
class CommandHandler {
  +EmergencyStop handle_emergency_stop()
  +SystemDiagnostic handle_system_diagnostic()
  +GetRobotInfo handle_get_robot_info()
}
BatteryMonitor --> "1" BatteryStatus
LidarSimulator --> "1" LidarScan
OdometrySimulator --> "1" Odometry
SensorProcessor --> "1" SensorFusion
SensorProcessor --> "1" LidarScan
SensorProcessor --> "1" Odometry
SensorProcessor --> "1" BatteryStatus
MissionPlanner --> "1" NavigateTo
MissionPlanner --> "1" BatteryStatus
CommandHandler --> "1" EmergencyStop
CommandHandler --> "1" SystemDiagnostic
CommandHandler --> "1" GetRobotInfo
```
