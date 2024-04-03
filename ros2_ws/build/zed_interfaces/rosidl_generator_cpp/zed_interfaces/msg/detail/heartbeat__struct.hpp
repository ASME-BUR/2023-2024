// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_HPP_
#define ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__zed_interfaces__msg__Heartbeat __attribute__((deprecated))
#else
# define DEPRECATED__zed_interfaces__msg__Heartbeat __declspec(deprecated)
#endif

namespace zed_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Heartbeat_
{
  using Type = Heartbeat_<ContainerAllocator>;

  explicit Heartbeat_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->beat_count = 0ull;
      this->node_ns = "";
      this->node_name = "";
      this->full_name = "";
      this->camera_sn = 0ul;
      this->svo_mode = false;
      this->simul_mode = false;
    }
  }

  explicit Heartbeat_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : node_ns(_alloc),
    node_name(_alloc),
    full_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->beat_count = 0ull;
      this->node_ns = "";
      this->node_name = "";
      this->full_name = "";
      this->camera_sn = 0ul;
      this->svo_mode = false;
      this->simul_mode = false;
    }
  }

  // field types and members
  using _beat_count_type =
    uint64_t;
  _beat_count_type beat_count;
  using _node_ns_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_ns_type node_ns;
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;
  using _full_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _full_name_type full_name;
  using _camera_sn_type =
    uint32_t;
  _camera_sn_type camera_sn;
  using _svo_mode_type =
    bool;
  _svo_mode_type svo_mode;
  using _simul_mode_type =
    bool;
  _simul_mode_type simul_mode;

  // setters for named parameter idiom
  Type & set__beat_count(
    const uint64_t & _arg)
  {
    this->beat_count = _arg;
    return *this;
  }
  Type & set__node_ns(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_ns = _arg;
    return *this;
  }
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }
  Type & set__full_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->full_name = _arg;
    return *this;
  }
  Type & set__camera_sn(
    const uint32_t & _arg)
  {
    this->camera_sn = _arg;
    return *this;
  }
  Type & set__svo_mode(
    const bool & _arg)
  {
    this->svo_mode = _arg;
    return *this;
  }
  Type & set__simul_mode(
    const bool & _arg)
  {
    this->simul_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zed_interfaces::msg::Heartbeat_<ContainerAllocator> *;
  using ConstRawPtr =
    const zed_interfaces::msg::Heartbeat_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zed_interfaces::msg::Heartbeat_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zed_interfaces::msg::Heartbeat_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zed_interfaces__msg__Heartbeat
    std::shared_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zed_interfaces__msg__Heartbeat
    std::shared_ptr<zed_interfaces::msg::Heartbeat_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Heartbeat_ & other) const
  {
    if (this->beat_count != other.beat_count) {
      return false;
    }
    if (this->node_ns != other.node_ns) {
      return false;
    }
    if (this->node_name != other.node_name) {
      return false;
    }
    if (this->full_name != other.full_name) {
      return false;
    }
    if (this->camera_sn != other.camera_sn) {
      return false;
    }
    if (this->svo_mode != other.svo_mode) {
      return false;
    }
    if (this->simul_mode != other.simul_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Heartbeat_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Heartbeat_

// alias to use template instance with default allocator
using Heartbeat =
  zed_interfaces::msg::Heartbeat_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zed_interfaces

#endif  // ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_HPP_
