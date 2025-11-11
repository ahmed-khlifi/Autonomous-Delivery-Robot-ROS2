// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/SystemDiagnostic.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/system_diagnostic__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SystemDiagnostic_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: full_report
  {
    out << "full_report: ";
    rosidl_generator_traits::value_to_yaml(msg.full_report, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SystemDiagnostic_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: full_report
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "full_report: ";
    rosidl_generator_traits::value_to_yaml(msg.full_report, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SystemDiagnostic_Request & msg, bool use_flow_style = false)
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
  const robot_interfaces::srv::SystemDiagnostic_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SystemDiagnostic_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SystemDiagnostic_Request>()
{
  return "robot_interfaces::srv::SystemDiagnostic_Request";
}

template<>
inline const char * name<robot_interfaces::srv::SystemDiagnostic_Request>()
{
  return "robot_interfaces/srv/SystemDiagnostic_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SystemDiagnostic_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SystemDiagnostic_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::SystemDiagnostic_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SystemDiagnostic_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: system_ok
  {
    out << "system_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.system_ok, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << ", ";
  }

  // member: components
  {
    if (msg.components.size() == 0) {
      out << "components: []";
    } else {
      out << "components: [";
      size_t pending_items = msg.components.size();
      for (auto item : msg.components) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: statuses
  {
    if (msg.statuses.size() == 0) {
      out << "statuses: []";
    } else {
      out << "statuses: [";
      size_t pending_items = msg.statuses.size();
      for (auto item : msg.statuses) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: error_count
  {
    out << "error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.error_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SystemDiagnostic_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: system_ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "system_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.system_ok, out);
    out << "\n";
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }

  // member: components
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.components.size() == 0) {
      out << "components: []\n";
    } else {
      out << "components:\n";
      for (auto item : msg.components) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: statuses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.statuses.size() == 0) {
      out << "statuses: []\n";
    } else {
      out << "statuses:\n";
      for (auto item : msg.statuses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: error_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.error_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SystemDiagnostic_Response & msg, bool use_flow_style = false)
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
  const robot_interfaces::srv::SystemDiagnostic_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SystemDiagnostic_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SystemDiagnostic_Response>()
{
  return "robot_interfaces::srv::SystemDiagnostic_Response";
}

template<>
inline const char * name<robot_interfaces::srv::SystemDiagnostic_Response>()
{
  return "robot_interfaces/srv/SystemDiagnostic_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SystemDiagnostic_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SystemDiagnostic_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::SystemDiagnostic_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::SystemDiagnostic>()
{
  return "robot_interfaces::srv::SystemDiagnostic";
}

template<>
inline const char * name<robot_interfaces::srv::SystemDiagnostic>()
{
  return "robot_interfaces/srv/SystemDiagnostic";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SystemDiagnostic>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::SystemDiagnostic_Request>::value &&
    has_fixed_size<robot_interfaces::srv::SystemDiagnostic_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::SystemDiagnostic>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::SystemDiagnostic_Request>::value &&
    has_bounded_size<robot_interfaces::srv::SystemDiagnostic_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::SystemDiagnostic>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::SystemDiagnostic_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::SystemDiagnostic_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__TRAITS_HPP_
