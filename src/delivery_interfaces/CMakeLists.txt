cmake_minimum_required(VERSION 3.5)
project(delivery_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/BatteryStatus.msg"
  "msg/LidarScan.msg"
  "msg/Odometry.msg"
  "msg/SensorFusion.msg"
  "srv/EmergencyStop.srv"
  "srv/SystemDiagnostic.srv"
  "srv/GetRobotInfo.srv"
  "action/NavigateTo.action"
  "action/DeliverPackage.action"
  "action/AutoCharge.action"
  DEPENDENCIES builtin_interfaces std_msgs geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
