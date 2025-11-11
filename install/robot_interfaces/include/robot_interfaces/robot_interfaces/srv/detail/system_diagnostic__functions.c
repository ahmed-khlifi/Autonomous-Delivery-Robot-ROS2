// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:srv/SystemDiagnostic.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/srv/detail/system_diagnostic__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
robot_interfaces__srv__SystemDiagnostic_Request__init(robot_interfaces__srv__SystemDiagnostic_Request * msg)
{
  if (!msg) {
    return false;
  }
  // full_report
  return true;
}

void
robot_interfaces__srv__SystemDiagnostic_Request__fini(robot_interfaces__srv__SystemDiagnostic_Request * msg)
{
  if (!msg) {
    return;
  }
  // full_report
}

bool
robot_interfaces__srv__SystemDiagnostic_Request__are_equal(const robot_interfaces__srv__SystemDiagnostic_Request * lhs, const robot_interfaces__srv__SystemDiagnostic_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // full_report
  if (lhs->full_report != rhs->full_report) {
    return false;
  }
  return true;
}

bool
robot_interfaces__srv__SystemDiagnostic_Request__copy(
  const robot_interfaces__srv__SystemDiagnostic_Request * input,
  robot_interfaces__srv__SystemDiagnostic_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // full_report
  output->full_report = input->full_report;
  return true;
}

robot_interfaces__srv__SystemDiagnostic_Request *
robot_interfaces__srv__SystemDiagnostic_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Request * msg = (robot_interfaces__srv__SystemDiagnostic_Request *)allocator.allocate(sizeof(robot_interfaces__srv__SystemDiagnostic_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__srv__SystemDiagnostic_Request));
  bool success = robot_interfaces__srv__SystemDiagnostic_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__srv__SystemDiagnostic_Request__destroy(robot_interfaces__srv__SystemDiagnostic_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__srv__SystemDiagnostic_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__init(robot_interfaces__srv__SystemDiagnostic_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Request * data = NULL;

  if (size) {
    data = (robot_interfaces__srv__SystemDiagnostic_Request *)allocator.zero_allocate(size, sizeof(robot_interfaces__srv__SystemDiagnostic_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__srv__SystemDiagnostic_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__srv__SystemDiagnostic_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__fini(robot_interfaces__srv__SystemDiagnostic_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_interfaces__srv__SystemDiagnostic_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_interfaces__srv__SystemDiagnostic_Request__Sequence *
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Request__Sequence * array = (robot_interfaces__srv__SystemDiagnostic_Request__Sequence *)allocator.allocate(sizeof(robot_interfaces__srv__SystemDiagnostic_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__srv__SystemDiagnostic_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__destroy(robot_interfaces__srv__SystemDiagnostic_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__srv__SystemDiagnostic_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__are_equal(const robot_interfaces__srv__SystemDiagnostic_Request__Sequence * lhs, const robot_interfaces__srv__SystemDiagnostic_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__srv__SystemDiagnostic_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__srv__SystemDiagnostic_Request__Sequence__copy(
  const robot_interfaces__srv__SystemDiagnostic_Request__Sequence * input,
  robot_interfaces__srv__SystemDiagnostic_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__srv__SystemDiagnostic_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__srv__SystemDiagnostic_Request * data =
      (robot_interfaces__srv__SystemDiagnostic_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__srv__SystemDiagnostic_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__srv__SystemDiagnostic_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__srv__SystemDiagnostic_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status_message`
// Member `components`
// Member `statuses`
#include "rosidl_runtime_c/string_functions.h"

bool
robot_interfaces__srv__SystemDiagnostic_Response__init(robot_interfaces__srv__SystemDiagnostic_Response * msg)
{
  if (!msg) {
    return false;
  }
  // system_ok
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    robot_interfaces__srv__SystemDiagnostic_Response__fini(msg);
    return false;
  }
  // components
  if (!rosidl_runtime_c__String__Sequence__init(&msg->components, 0)) {
    robot_interfaces__srv__SystemDiagnostic_Response__fini(msg);
    return false;
  }
  // statuses
  if (!rosidl_runtime_c__String__Sequence__init(&msg->statuses, 0)) {
    robot_interfaces__srv__SystemDiagnostic_Response__fini(msg);
    return false;
  }
  // battery_level
  // error_count
  return true;
}

void
robot_interfaces__srv__SystemDiagnostic_Response__fini(robot_interfaces__srv__SystemDiagnostic_Response * msg)
{
  if (!msg) {
    return;
  }
  // system_ok
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
  // components
  rosidl_runtime_c__String__Sequence__fini(&msg->components);
  // statuses
  rosidl_runtime_c__String__Sequence__fini(&msg->statuses);
  // battery_level
  // error_count
}

bool
robot_interfaces__srv__SystemDiagnostic_Response__are_equal(const robot_interfaces__srv__SystemDiagnostic_Response * lhs, const robot_interfaces__srv__SystemDiagnostic_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // system_ok
  if (lhs->system_ok != rhs->system_ok) {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_message), &(rhs->status_message)))
  {
    return false;
  }
  // components
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->components), &(rhs->components)))
  {
    return false;
  }
  // statuses
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->statuses), &(rhs->statuses)))
  {
    return false;
  }
  // battery_level
  if (lhs->battery_level != rhs->battery_level) {
    return false;
  }
  // error_count
  if (lhs->error_count != rhs->error_count) {
    return false;
  }
  return true;
}

bool
robot_interfaces__srv__SystemDiagnostic_Response__copy(
  const robot_interfaces__srv__SystemDiagnostic_Response * input,
  robot_interfaces__srv__SystemDiagnostic_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // system_ok
  output->system_ok = input->system_ok;
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  // components
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->components), &(output->components)))
  {
    return false;
  }
  // statuses
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->statuses), &(output->statuses)))
  {
    return false;
  }
  // battery_level
  output->battery_level = input->battery_level;
  // error_count
  output->error_count = input->error_count;
  return true;
}

robot_interfaces__srv__SystemDiagnostic_Response *
robot_interfaces__srv__SystemDiagnostic_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Response * msg = (robot_interfaces__srv__SystemDiagnostic_Response *)allocator.allocate(sizeof(robot_interfaces__srv__SystemDiagnostic_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__srv__SystemDiagnostic_Response));
  bool success = robot_interfaces__srv__SystemDiagnostic_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__srv__SystemDiagnostic_Response__destroy(robot_interfaces__srv__SystemDiagnostic_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__srv__SystemDiagnostic_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__init(robot_interfaces__srv__SystemDiagnostic_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Response * data = NULL;

  if (size) {
    data = (robot_interfaces__srv__SystemDiagnostic_Response *)allocator.zero_allocate(size, sizeof(robot_interfaces__srv__SystemDiagnostic_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__srv__SystemDiagnostic_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__srv__SystemDiagnostic_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__fini(robot_interfaces__srv__SystemDiagnostic_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_interfaces__srv__SystemDiagnostic_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_interfaces__srv__SystemDiagnostic_Response__Sequence *
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__srv__SystemDiagnostic_Response__Sequence * array = (robot_interfaces__srv__SystemDiagnostic_Response__Sequence *)allocator.allocate(sizeof(robot_interfaces__srv__SystemDiagnostic_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__srv__SystemDiagnostic_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__destroy(robot_interfaces__srv__SystemDiagnostic_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__srv__SystemDiagnostic_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__are_equal(const robot_interfaces__srv__SystemDiagnostic_Response__Sequence * lhs, const robot_interfaces__srv__SystemDiagnostic_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__srv__SystemDiagnostic_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__srv__SystemDiagnostic_Response__Sequence__copy(
  const robot_interfaces__srv__SystemDiagnostic_Response__Sequence * input,
  robot_interfaces__srv__SystemDiagnostic_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__srv__SystemDiagnostic_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__srv__SystemDiagnostic_Response * data =
      (robot_interfaces__srv__SystemDiagnostic_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__srv__SystemDiagnostic_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__srv__SystemDiagnostic_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__srv__SystemDiagnostic_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
