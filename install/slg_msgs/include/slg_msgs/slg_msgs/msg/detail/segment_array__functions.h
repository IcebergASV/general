// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__FUNCTIONS_H_
#define SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "slg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "slg_msgs/msg/detail/segment_array__struct.h"

/// Initialize msg/SegmentArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * slg_msgs__msg__SegmentArray
 * )) before or use
 * slg_msgs__msg__SegmentArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__SegmentArray__init(slg_msgs__msg__SegmentArray * msg);

/// Finalize msg/SegmentArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__SegmentArray__fini(slg_msgs__msg__SegmentArray * msg);

/// Create msg/SegmentArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * slg_msgs__msg__SegmentArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
slg_msgs__msg__SegmentArray *
slg_msgs__msg__SegmentArray__create();

/// Destroy msg/SegmentArray message.
/**
 * It calls
 * slg_msgs__msg__SegmentArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__SegmentArray__destroy(slg_msgs__msg__SegmentArray * msg);

/// Check for msg/SegmentArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__SegmentArray__are_equal(const slg_msgs__msg__SegmentArray * lhs, const slg_msgs__msg__SegmentArray * rhs);

/// Copy a msg/SegmentArray message.
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
slg_msgs__msg__SegmentArray__copy(
  const slg_msgs__msg__SegmentArray * input,
  slg_msgs__msg__SegmentArray * output);

/// Initialize array of msg/SegmentArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * slg_msgs__msg__SegmentArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__SegmentArray__Sequence__init(slg_msgs__msg__SegmentArray__Sequence * array, size_t size);

/// Finalize array of msg/SegmentArray messages.
/**
 * It calls
 * slg_msgs__msg__SegmentArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__SegmentArray__Sequence__fini(slg_msgs__msg__SegmentArray__Sequence * array);

/// Create array of msg/SegmentArray messages.
/**
 * It allocates the memory for the array and calls
 * slg_msgs__msg__SegmentArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
slg_msgs__msg__SegmentArray__Sequence *
slg_msgs__msg__SegmentArray__Sequence__create(size_t size);

/// Destroy array of msg/SegmentArray messages.
/**
 * It calls
 * slg_msgs__msg__SegmentArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
void
slg_msgs__msg__SegmentArray__Sequence__destroy(slg_msgs__msg__SegmentArray__Sequence * array);

/// Check for msg/SegmentArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slg_msgs
bool
slg_msgs__msg__SegmentArray__Sequence__are_equal(const slg_msgs__msg__SegmentArray__Sequence * lhs, const slg_msgs__msg__SegmentArray__Sequence * rhs);

/// Copy an array of msg/SegmentArray messages.
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
slg_msgs__msg__SegmentArray__Sequence__copy(
  const slg_msgs__msg__SegmentArray__Sequence * input,
  slg_msgs__msg__SegmentArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__FUNCTIONS_H_
