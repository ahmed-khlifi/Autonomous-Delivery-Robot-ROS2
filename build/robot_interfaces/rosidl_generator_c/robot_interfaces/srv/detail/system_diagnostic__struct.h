// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/SystemDiagnostic.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SystemDiagnostic in the package robot_interfaces.
typedef struct robot_interfaces__srv__SystemDiagnostic_Request
{
  /// True for detailed report
  bool full_report;
} robot_interfaces__srv__SystemDiagnostic_Request;

// Struct for a sequence of robot_interfaces__srv__SystemDiagnostic_Request.
typedef struct robot_interfaces__srv__SystemDiagnostic_Request__Sequence
{
  robot_interfaces__srv__SystemDiagnostic_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__SystemDiagnostic_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status_message'
// Member 'components'
// Member 'statuses'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SystemDiagnostic in the package robot_interfaces.
typedef struct robot_interfaces__srv__SystemDiagnostic_Response
{
  bool system_ok;
  rosidl_runtime_c__String status_message;
  /// ["battery", "motors", "sensors", "navigation"]
  rosidl_runtime_c__String__Sequence components;
  /// ["OK", "WARNING", "ERROR"] corresponding to components
  rosidl_runtime_c__String__Sequence statuses;
  float battery_level;
  int32_t error_count;
} robot_interfaces__srv__SystemDiagnostic_Response;

// Struct for a sequence of robot_interfaces__srv__SystemDiagnostic_Response.
typedef struct robot_interfaces__srv__SystemDiagnostic_Response__Sequence
{
  robot_interfaces__srv__SystemDiagnostic_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__SystemDiagnostic_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_H_
