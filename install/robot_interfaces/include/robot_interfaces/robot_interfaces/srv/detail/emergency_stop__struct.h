// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/EmergencyStop.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/EmergencyStop in the package robot_interfaces.
typedef struct robot_interfaces__srv__EmergencyStop_Request
{
  /// True to activate emergency stop
  bool emergency;
} robot_interfaces__srv__EmergencyStop_Request;

// Struct for a sequence of robot_interfaces__srv__EmergencyStop_Request.
typedef struct robot_interfaces__srv__EmergencyStop_Request__Sequence
{
  robot_interfaces__srv__EmergencyStop_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__EmergencyStop_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/EmergencyStop in the package robot_interfaces.
typedef struct robot_interfaces__srv__EmergencyStop_Response
{
  /// Whether stop was executed
  bool success;
  /// Status message
  rosidl_runtime_c__String message;
} robot_interfaces__srv__EmergencyStop_Response;

// Struct for a sequence of robot_interfaces__srv__EmergencyStop_Response.
typedef struct robot_interfaces__srv__EmergencyStop_Response__Sequence
{
  robot_interfaces__srv__EmergencyStop_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__EmergencyStop_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__STRUCT_H_
