// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/GetRobotInfo.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/get_robot_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::GetRobotInfo_Request>()
{
  return ::robot_interfaces::srv::GetRobotInfo_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotInfo_Response_active_topics
{
public:
  explicit Init_GetRobotInfo_Response_active_topics(::robot_interfaces::srv::GetRobotInfo_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::GetRobotInfo_Response active_topics(::robot_interfaces::srv::GetRobotInfo_Response::_active_topics_type arg)
  {
    msg_.active_topics = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

class Init_GetRobotInfo_Response_current_mission
{
public:
  explicit Init_GetRobotInfo_Response_current_mission(::robot_interfaces::srv::GetRobotInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotInfo_Response_active_topics current_mission(::robot_interfaces::srv::GetRobotInfo_Response::_current_mission_type arg)
  {
    msg_.current_mission = std::move(arg);
    return Init_GetRobotInfo_Response_active_topics(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

class Init_GetRobotInfo_Response_battery_level
{
public:
  explicit Init_GetRobotInfo_Response_battery_level(::robot_interfaces::srv::GetRobotInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotInfo_Response_current_mission battery_level(::robot_interfaces::srv::GetRobotInfo_Response::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_GetRobotInfo_Response_current_mission(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

class Init_GetRobotInfo_Response_position_y
{
public:
  explicit Init_GetRobotInfo_Response_position_y(::robot_interfaces::srv::GetRobotInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotInfo_Response_battery_level position_y(::robot_interfaces::srv::GetRobotInfo_Response::_position_y_type arg)
  {
    msg_.position_y = std::move(arg);
    return Init_GetRobotInfo_Response_battery_level(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

class Init_GetRobotInfo_Response_position_x
{
public:
  explicit Init_GetRobotInfo_Response_position_x(::robot_interfaces::srv::GetRobotInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotInfo_Response_position_y position_x(::robot_interfaces::srv::GetRobotInfo_Response::_position_x_type arg)
  {
    msg_.position_x = std::move(arg);
    return Init_GetRobotInfo_Response_position_y(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

class Init_GetRobotInfo_Response_robot_state
{
public:
  Init_GetRobotInfo_Response_robot_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotInfo_Response_position_x robot_state(::robot_interfaces::srv::GetRobotInfo_Response::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_GetRobotInfo_Response_position_x(msg_);
  }

private:
  ::robot_interfaces::srv::GetRobotInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::GetRobotInfo_Response>()
{
  return robot_interfaces::srv::builder::Init_GetRobotInfo_Response_robot_state();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__BUILDER_HPP_
