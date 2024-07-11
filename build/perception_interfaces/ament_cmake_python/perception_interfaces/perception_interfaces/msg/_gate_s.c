// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "perception_interfaces/msg/detail/gate__struct.h"
#include "perception_interfaces/msg/detail/gate__functions.h"

bool perception_interfaces__msg__prop__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * perception_interfaces__msg__prop__convert_to_py(void * raw_ros_message);
bool perception_interfaces__msg__prop__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * perception_interfaces__msg__prop__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool perception_interfaces__msg__gate__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("perception_interfaces.msg._gate.Gate", full_classname_dest, 36) == 0);
  }
  perception_interfaces__msg__Gate * ros_message = _ros_message;
  {  // red_marker
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_marker");
    if (!field) {
      return false;
    }
    if (!perception_interfaces__msg__prop__convert_from_py(field, &ros_message->red_marker)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // green_marker
    PyObject * field = PyObject_GetAttrString(_pymsg, "green_marker");
    if (!field) {
      return false;
    }
    if (!perception_interfaces__msg__prop__convert_from_py(field, &ros_message->green_marker)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // midpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "midpoint");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__point__convert_from_py(field, &ros_message->midpoint)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * perception_interfaces__msg__gate__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Gate */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("perception_interfaces.msg._gate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Gate");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  perception_interfaces__msg__Gate * ros_message = (perception_interfaces__msg__Gate *)raw_ros_message;
  {  // red_marker
    PyObject * field = NULL;
    field = perception_interfaces__msg__prop__convert_to_py(&ros_message->red_marker);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_marker", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // green_marker
    PyObject * field = NULL;
    field = perception_interfaces__msg__prop__convert_to_py(&ros_message->green_marker);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "green_marker", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // midpoint
    PyObject * field = NULL;
    field = geometry_msgs__msg__point__convert_to_py(&ros_message->midpoint);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "midpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
