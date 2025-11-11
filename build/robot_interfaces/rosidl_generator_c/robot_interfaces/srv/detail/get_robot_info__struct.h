// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/GetRobotInfo.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRobotInfo in the package robot_interfaces.
typedef struct robot_interfaces__srv__GetRobotInfo_Request
{
  uint8_t structure_needs_at_least_one_member;
} robot_interfaces__srv__GetRobotInfo_Request;

// Struct for a sequence of robot_interfaces__srv__GetRobotInfo_Request.
typedef struct robot_interfaces__srv__GetRobotInfo_Request__Sequence
{
  robot_interfaces__srv__GetRobotInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__GetRobotInfo_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'robot_state'
// Member 'current_mission'
// Member 'active_topics'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetRobotInfo in the package robot_interfaces.
typedef struct robot_interfaces__srv__GetRobotInfo_Response
{
  /// "IDLE", "NAVIGATING", "DELIVERING", "CHARGING", "ERROR", "RETURNING_TO_CHARGE"
  rosidl_runtime_c__String robot_state;
  float position_x;
  float position_y;
  float battery_level;
  /// Current mission description
  rosidl_runtime_c__String current_mission;
  /// List of active topics
  rosidl_runtime_c__String__Sequence active_topics;
} robot_interfaces__srv__GetRobotInfo_Response;

// Struct for a sequence of robot_interfaces__srv__GetRobotInfo_Response.
typedef struct robot_interfaces__srv__GetRobotInfo_Response__Sequence
{
  robot_interfaces__srv__GetRobotInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__GetRobotInfo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__STRUCT_H_
