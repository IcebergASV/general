// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT__FUNCTIONS_H_
#define SLG_MSGS__MSG__DETAIL__SEGMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "slg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "slg_msgs/msg/detail/segment__struct.h"

/// Initialize msg/Segment message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * slg_msgs__msg__Segment
 * )) before or use
 * slg_msgs__msg__Segment__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__init(slg_msgs__msg__Segment * msg);

/// Finalize msg/Segment message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__Segment__fini(slg_msgs__msg__Segment * msg);

/// Create msg/Segment message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * slg_msgs__msg__Segment__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
slg_msgs__msg__Segment *
slg_msgs__msg__Segment__create();

/// Destroy msg/Segment message.
/**
 * It calls
 * slg_msgs__msg__Segment__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__Segment__destroy(slg_msgs__msg__Segment * msg);

/// Check for msg/Segment message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__are_equal(const slg_msgs__msg__Segment * lhs, const slg_msgs__msg__Segment * rhs);

/// Copy a msg/Segment message.
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
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__copy(
  const slg_msgs__msg__Segment * input,
  slg_msgs__msg__Segment * output);

/// Initialize array of msg/Segment messages.
/**
 * It allocates the memory for the number of elements and calls
 * slg_msgs__msg__Segment__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__Sequence__init(slg_msgs__msg__Segment__Sequence * array, size_t size);

/// Finalize array of msg/Segment messages.
/**
 * It calls
 * slg_msgs__msg__Segment__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__Segment__Sequence__fini(slg_msgs__msg__Segment__Sequence * array);

/// Create array of msg/Segment messages.
/**
 * It allocates the memory for the array and calls
 * slg_msgs__msg__Segment__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
slg_msgs__msg__Segment__Sequence *
slg_msgs__msg__Segment__Sequence__create(size_t size);

/// Destroy array of msg/Segment messages.
/**
 * It calls
 * slg_msgs__msg__Segment__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__Segment__Sequence__destroy(slg_msgs__msg__Segment__Sequence * array);

/// Check for msg/Segment message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__Sequence__are_equal(const slg_msgs__msg__Segment__Sequence * lhs, const slg_msgs__msg__Segment__Sequence * rhs);

/// Copy an array of msg/Segment messages.
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
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__Segment__Sequence__copy(
  const slg_msgs__msg__Segment__Sequence * input,
  slg_msgs__msg__Segment__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT__FUNCTIONS_H_
