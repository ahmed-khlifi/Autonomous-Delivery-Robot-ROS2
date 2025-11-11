// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/SystemDiagnostic.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SystemDiagnostic_Request_
{
  using Type = SystemDiagnostic_Request_<ContainerAllocator>;

  explicit SystemDiagnostic_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_report = false;
    }
  }

  explicit SystemDiagnostic_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_report = false;
    }
  }

  // field types and members
  using _full_report_type =
    bool;
  _full_report_type full_report;

  // setters for named parameter idiom
  Type & set__full_report(
    const bool & _arg)
  {
    this->full_report = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Request
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Request
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemDiagnostic_Request_ & other) const
  {
    if (this->full_report != other.full_report) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemDiagnostic_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemDiagnostic_Request_

// alias to use template instance with default allocator
using SystemDiagnostic_Request =
  robot_interfaces::srv::SystemDiagnostic_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SystemDiagnostic_Response_
{
  using Type = SystemDiagnostic_Response_<ContainerAllocator>;

  explicit SystemDiagnostic_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_ok = false;
      this->status_message = "";
      this->battery_level = 0.0f;
      this->error_count = 0l;
    }
  }

  explicit SystemDiagnostic_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_ok = false;
      this->status_message = "";
      this->battery_level = 0.0f;
      this->error_count = 0l;
    }
  }

  // field types and members
  using _system_ok_type =
    bool;
  _system_ok_type system_ok;
  using _status_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_message_type status_message;
  using _components_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _components_type components;
  using _statuses_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _statuses_type statuses;
  using _battery_level_type =
    float;
  _battery_level_type battery_level;
  using _error_count_type =
    int32_t;
  _error_count_type error_count;

  // setters for named parameter idiom
  Type & set__system_ok(
    const bool & _arg)
  {
    this->system_ok = _arg;
    return *this;
  }
  Type & set__status_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_message = _arg;
    return *this;
  }
  Type & set__components(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->components = _arg;
    return *this;
  }
  Type & set__statuses(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->statuses = _arg;
    return *this;
  }
  Type & set__battery_level(
    const float & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__error_count(
    const int32_t & _arg)
  {
    this->error_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Response
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SystemDiagnostic_Response
    std::shared_ptr<robot_interfaces::srv::SystemDiagnostic_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemDiagnostic_Response_ & other) const
  {
    if (this->system_ok != other.system_ok) {
      return false;
    }
    if (this->status_message != other.status_message) {
      return false;
    }
    if (this->components != other.components) {
      return false;
    }
    if (this->statuses != other.statuses) {
      return false;
    }
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->error_count != other.error_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemDiagnostic_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemDiagnostic_Response_

// alias to use template instance with default allocator
using SystemDiagnostic_Response =
  robot_interfaces::srv::SystemDiagnostic_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct SystemDiagnostic
{
  using Request = robot_interfaces::srv::SystemDiagnostic_Request;
  using Response = robot_interfaces::srv::SystemDiagnostic_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SYSTEM_DIAGNOSTIC__STRUCT_HPP_
