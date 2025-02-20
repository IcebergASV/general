// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__FUNCTIONS_H_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "comp_tasks_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "comp_tasks_interfaces/msg/detail/start_task__struct.h"

/// Initialize msg/StartTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * comp_tasks_interfaces__msg__StartTask
 * )) before or use
 * comp_tasks_interfaces__msg__StartTask__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__init(comp_tasks_interfaces__msg__StartTask * msg);

/// Finalize msg/StartTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
void
comp_tasks_interfaces__msg__StartTask__fini(comp_tasks_interfaces__msg__StartTask * msg);

/// Create msg/StartTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * comp_tasks_interfaces__msg__StartTask__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
comp_tasks_interfaces__msg__StartTask *
comp_tasks_interfaces__msg__StartTask__create();

/// Destroy msg/StartTask message.
/**
 * It calls
 * comp_tasks_interfaces__msg__StartTask__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
void
comp_tasks_interfaces__msg__StartTask__destroy(comp_tasks_interfaces__msg__StartTask * msg);

/// Check for msg/StartTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__are_equal(const comp_tasks_interfaces__msg__StartTask * lhs, const comp_tasks_interfaces__msg__StartTask * rhs);

/// Copy a msg/StartTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__copy(
  const comp_tasks_interfaces__msg__StartTask * input,
  comp_tasks_interfaces__msg__StartTask * output);

/// Initialize array of msg/StartTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * comp_tasks_interfaces__msg__StartTask__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__Sequence__init(comp_tasks_interfaces__msg__StartTask__Sequence * array, size_t size);

/// Finalize array of msg/StartTask messages.
/**
 * It calls
 * comp_tasks_interfaces__msg__StartTask__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
void
comp_tasks_interfaces__msg__StartTask__Sequence__fini(comp_tasks_interfaces__msg__StartTask__Sequence * array);

/// Create array of msg/StartTask messages.
/**
 * It allocates the memory for the array and calls
 * comp_tasks_interfaces__msg__StartTask__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
comp_tasks_interfaces__msg__StartTask__Sequence *
comp_tasks_interfaces__msg__StartTask__Sequence__create(size_t size);

/// Destroy array of msg/StartTask messages.
/**
 * It calls
 * comp_tasks_interfaces__msg__StartTask__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
void
comp_tasks_interfaces__msg__StartTask__Sequence__destroy(comp_tasks_interfaces__msg__StartTask__Sequence * array);

/// Check for msg/StartTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__Sequence__are_equal(const comp_tasks_interfaces__msg__StartTask__Sequence * lhs, const comp_tasks_interfaces__msg__StartTask__Sequence * rhs);

/// Copy an array of msg/StartTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_tasks_interfaces
bool
comp_tasks_interfaces__msg__StartTask__Sequence__copy(
  const comp_tasks_interfaces__msg__StartTask__Sequence * input,
  comp_tasks_interfaces__msg__StartTask__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__FUNCTIONS_H_
