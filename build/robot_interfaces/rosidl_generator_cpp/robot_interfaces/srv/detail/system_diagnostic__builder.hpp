// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/SystemDiagnostic.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/system_diagnostic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SystemDiagnostic_Request_full_report
{
public:
  Init_SystemDiagnostic_Request_full_report()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::SystemDiagnostic_Request full_report(::robot_interfaces::srv::SystemDiagnostic_Request::_full_report_type arg)
  {
    msg_.full_report = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SystemDiagnostic_Request>()
{
  return robot_interfaces::srv::builder::Init_SystemDiagnostic_Request_full_report();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SystemDiagnostic_Response_error_count
{
public:
  explicit Init_SystemDiagnostic_Response_error_count(::robot_interfaces::srv::SystemDiagnostic_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::SystemDiagnostic_Response error_count(::robot_interfaces::srv::SystemDiagnostic_Response::_error_count_type arg)
  {
    msg_.error_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

class Init_SystemDiagnostic_Response_battery_level
{
public:
  explicit Init_SystemDiagnostic_Response_battery_level(::robot_interfaces::srv::SystemDiagnostic_Response & msg)
  : msg_(msg)
  {}
  Init_SystemDiagnostic_Response_error_count battery_level(::robot_interfaces::srv::SystemDiagnostic_Response::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_SystemDiagnostic_Response_error_count(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

class Init_SystemDiagnostic_Response_statuses
{
public:
  explicit Init_SystemDiagnostic_Response_statuses(::robot_interfaces::srv::SystemDiagnostic_Response & msg)
  : msg_(msg)
  {}
  Init_SystemDiagnostic_Response_battery_level statuses(::robot_interfaces::srv::SystemDiagnostic_Response::_statuses_type arg)
  {
    msg_.statuses = std::move(arg);
    return Init_SystemDiagnostic_Response_battery_level(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

class Init_SystemDiagnostic_Response_components
{
public:
  explicit Init_SystemDiagnostic_Response_components(::robot_interfaces::srv::SystemDiagnostic_Response & msg)
  : msg_(msg)
  {}
  Init_SystemDiagnostic_Response_statuses components(::robot_interfaces::srv::SystemDiagnostic_Response::_components_type arg)
  {
    msg_.components = std::move(arg);
    return Init_SystemDiagnostic_Response_statuses(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

class Init_SystemDiagnostic_Response_status_message
{
public:
  explicit Init_SystemDiagnostic_Response_status_message(::robot_interfaces::srv::SystemDiagnostic_Response & msg)
  : msg_(msg)
  {}
  Init_SystemDiagnostic_Response_components status_message(::robot_interfaces::srv::SystemDiagnostic_Response::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return Init_SystemDiagnostic_Response_components(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

class Init_SystemDiagnostic_Response_system_ok
{
public:
  Init_SystemDiagnostic_Response_system_ok()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemDiagnostic_Response_status_message system_ok(::robot_interfaces::srv::SystemDiagnostic_Response::_system_ok_type arg)
  {
    msg_.system_ok = std::move(arg);
    return Init_SystemDiagnostic_Response_status_message(msg_);
  }

private:
  ::robot_interfaces::srv::SystemDiagnostic_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SystemDiagnostic_Response>()
{
  return robot_interfaces::srv::builder::Init_SystemDiagnostic_Response_system_ok();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__BUILDER_HPP_
