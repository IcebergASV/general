// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from yolov8_msgs:msg/IcebergDetection.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__FUNCTIONS_H_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "yolov8_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "yolov8_msgs/msg/detail/iceberg_detection__struct.h"

/// Initialize msg/IcebergDetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * yolov8_msgs__msg__IcebergDetection
 * )) before or use
 * yolov8_msgs__msg__IcebergDetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__init(yolov8_msgs__msg__IcebergDetection * msg);

/// Finalize msg/IcebergDetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
void
yolov8_msgs__msg__IcebergDetection__fini(yolov8_msgs__msg__IcebergDetection * msg);

/// Create msg/IcebergDetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * yolov8_msgs__msg__IcebergDetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
yolov8_msgs__msg__IcebergDetection *
yolov8_msgs__msg__IcebergDetection__create();

/// Destroy msg/IcebergDetection message.
/**
 * It calls
 * yolov8_msgs__msg__IcebergDetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
void
yolov8_msgs__msg__IcebergDetection__destroy(yolov8_msgs__msg__IcebergDetection * msg);

/// Check for msg/IcebergDetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__are_equal(const yolov8_msgs__msg__IcebergDetection * lhs, const yolov8_msgs__msg__IcebergDetection * rhs);

/// Copy a msg/IcebergDetection message.
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
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__copy(
  const yolov8_msgs__msg__IcebergDetection * input,
  yolov8_msgs__msg__IcebergDetection * output);

/// Initialize array of msg/IcebergDetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * yolov8_msgs__msg__IcebergDetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__Sequence__init(yolov8_msgs__msg__IcebergDetection__Sequence * array, size_t size);

/// Finalize array of msg/IcebergDetection messages.
/**
 * It calls
 * yolov8_msgs__msg__IcebergDetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
void
yolov8_msgs__msg__IcebergDetection__Sequence__fini(yolov8_msgs__msg__IcebergDetection__Sequence * array);

/// Create array of msg/IcebergDetection messages.
/**
 * It allocates the memory for the array and calls
 * yolov8_msgs__msg__IcebergDetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
yolov8_msgs__msg__IcebergDetection__Sequence *
yolov8_msgs__msg__IcebergDetection__Sequence__create(size_t size);

/// Destroy array of msg/IcebergDetection messages.
/**
 * It calls
 * yolov8_msgs__msg__IcebergDetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
void
yolov8_msgs__msg__IcebergDetection__Sequence__destroy(yolov8_msgs__msg__IcebergDetection__Sequence * array);

/// Check for msg/IcebergDetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__Sequence__are_equal(const yolov8_msgs__msg__IcebergDetection__Sequence * lhs, const yolov8_msgs__msg__IcebergDetection__Sequence * rhs);

/// Copy an array of msg/IcebergDetection messages.
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
ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
bool
yolov8_msgs__msg__IcebergDetection__Sequence__copy(
  const yolov8_msgs__msg__IcebergDetection__Sequence * input,
  yolov8_msgs__msg__IcebergDetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__FUNCTIONS_H_
