// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/EmergencyStop.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/emergency_stop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_EmergencyStop_Request_emergency
{
public:
  Init_EmergencyStop_Request_emergency()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::EmergencyStop_Request emergency(::robot_interfaces::srv::EmergencyStop_Request::_emergency_type arg)
  {
    msg_.emergency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::EmergencyStop_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::EmergencyStop_Request>()
{
  return robot_interfaces::srv::builder::Init_EmergencyStop_Request_emergency();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_EmergencyStop_Response_message
{
public:
  explicit Init_EmergencyStop_Response_message(::robot_interfaces::srv::EmergencyStop_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::EmergencyStop_Response message(::robot_interfaces::srv::EmergencyStop_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::EmergencyStop_Response msg_;
};

class Init_EmergencyStop_Response_success
{
public:
  Init_EmergencyStop_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EmergencyStop_Response_message success(::robot_interfaces::srv::EmergencyStop_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_EmergencyStop_Response_message(msg_);
  }

private:
  ::robot_interfaces::srv::EmergencyStop_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::EmergencyStop_Response>()
{
  return robot_interfaces::srv::builder::Init_EmergencyStop_Response_success();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__EMERGENCY_STOP__BUILDER_HPP_
