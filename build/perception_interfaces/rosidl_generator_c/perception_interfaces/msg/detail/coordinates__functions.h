// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from perception_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__FUNCTIONS_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "perception_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "perception_interfaces/msg/detail/coordinates__struct.h"

/// Initialize msg/Coordinates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * perception_interfaces__msg__Coordinates
 * )) before or use
 * perception_interfaces__msg__Coordinates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__init(perception_interfaces__msg__Coordinates * msg);

/// Finalize msg/Coordinates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
void
perception_interfaces__msg__Coordinates__fini(perception_interfaces__msg__Coordinates * msg);

/// Create msg/Coordinates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * perception_interfaces__msg__Coordinates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
perception_interfaces__msg__Coordinates *
perception_interfaces__msg__Coordinates__create();

/// Destroy msg/Coordinates message.
/**
 * It calls
 * perception_interfaces__msg__Coordinates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
void
perception_interfaces__msg__Coordinates__destroy(perception_interfaces__msg__Coordinates * msg);

/// Check for msg/Coordinates message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__are_equal(const perception_interfaces__msg__Coordinates * lhs, const perception_interfaces__msg__Coordinates * rhs);

/// Copy a msg/Coordinates message.
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
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__copy(
  const perception_interfaces__msg__Coordinates * input,
  perception_interfaces__msg__Coordinates * output);

/// Initialize array of msg/Coordinates messages.
/**
 * It allocates the memory for the number of elements and calls
 * perception_interfaces__msg__Coordinates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__Sequence__init(perception_interfaces__msg__Coordinates__Sequence * array, size_t size);

/// Finalize array of msg/Coordinates messages.
/**
 * It calls
 * perception_interfaces__msg__Coordinates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
void
perception_interfaces__msg__Coordinates__Sequence__fini(perception_interfaces__msg__Coordinates__Sequence * array);

/// Create array of msg/Coordinates messages.
/**
 * It allocates the memory for the array and calls
 * perception_interfaces__msg__Coordinates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
perception_interfaces__msg__Coordinates__Sequence *
perception_interfaces__msg__Coordinates__Sequence__create(size_t size);

/// Destroy array of msg/Coordinates messages.
/**
 * It calls
 * perception_interfaces__msg__Coordinates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
void
perception_interfaces__msg__Coordinates__Sequence__destroy(perception_interfaces__msg__Coordinates__Sequence * array);

/// Check for msg/Coordinates message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__Sequence__are_equal(const perception_interfaces__msg__Coordinates__Sequence * lhs, const perception_interfaces__msg__Coordinates__Sequence * rhs);

/// Copy an array of msg/Coordinates messages.
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
ROSIDL_GENERATOR_C_PUBLIC_perception_interfaces
bool
perception_interfaces__msg__Coordinates__Sequence__copy(
  const perception_interfaces__msg__Coordinates__Sequence * input,
  perception_interfaces__msg__Coordinates__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__FUNCTIONS_H_
