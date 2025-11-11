// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/GetRobotInfo.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/get_robot_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotInfo_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRobotInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRobotInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::GetRobotInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::GetRobotInfo_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::GetRobotInfo_Request>()
{
  return "robot_interfaces::srv::GetRobotInfo_Request";
}

template<>
inline const char * name<robot_interfaces::srv::GetRobotInfo_Request>()
{
  return "robot_interfaces/srv/GetRobotInfo_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::GetRobotInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::GetRobotInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::GetRobotInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_state
  {
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << ", ";
  }

  // member: position_x
  {
    out << "position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.position_x, out);
    out << ", ";
  }

  // member: position_y
  {
    out << "position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.position_y, out);
    out << ", ";
  }

  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: current_mission
  {
    out << "current_mission: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mission, out);
    out << ", ";
  }

  // member: active_topics
  {
    if (msg.active_topics.size() == 0) {
      out << "active_topics: []";
    } else {
      out << "active_topics: [";
      size_t pending_items = msg.active_topics.size();
      for (auto item : msg.active_topics) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRobotInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << "\n";
  }

  // member: position_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.position_x, out);
    out << "\n";
  }

  // member: position_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.position_y, out);
    out << "\n";
  }

  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << "\n";
  }

  // member: current_mission
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_mission: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mission, out);
    out << "\n";
  }

  // member: active_topics
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.active_topics.size() == 0) {
      out << "active_topics: []\n";
    } else {
      out << "active_topics:\n";
      for (auto item : msg.active_topics) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRobotInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::GetRobotInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::GetRobotInfo_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::GetRobotInfo_Response>()
{
  return "robot_interfaces::srv::GetRobotInfo_Response";
}

template<>
inline const char * name<robot_interfaces::srv::GetRobotInfo_Response>()
{
  return "robot_interfaces/srv/GetRobotInfo_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::GetRobotInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::GetRobotInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::GetRobotInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::GetRobotInfo>()
{
  return "robot_interfaces::srv::GetRobotInfo";
}

template<>
inline const char * name<robot_interfaces::srv::GetRobotInfo>()
{
  return "robot_interfaces/srv/GetRobotInfo";
}

template<>
struct has_fixed_size<robot_interfaces::srv::GetRobotInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::GetRobotInfo_Request>::value &&
    has_fixed_size<robot_interfaces::srv::GetRobotInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::GetRobotInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::GetRobotInfo_Request>::value &&
    has_bounded_size<robot_interfaces::srv::GetRobotInfo_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::GetRobotInfo>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::GetRobotInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::GetRobotInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__GET_ROBOT_INFO__TRAITS_HPP_
