// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from zed_interfaces:msg/Heartbeat.idl
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
#include "zed_interfaces/msg/detail/heartbeat__struct.h"
#include "zed_interfaces/msg/detail/heartbeat__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool zed_interfaces__msg__heartbeat__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("zed_interfaces.msg._heartbeat.Heartbeat", full_classname_dest, 39) == 0);
  }
  zed_interfaces__msg__Heartbeat * ros_message = _ros_message;
  {  // beat_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "beat_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->beat_count = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // node_ns
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_ns");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->node_ns, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // node_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->node_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // full_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "full_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->full_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // camera_sn
    PyObject * field = PyObject_GetAttrString(_pymsg, "camera_sn");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->camera_sn = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // svo_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "svo_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->svo_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // simul_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "simul_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->simul_mode = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * zed_interfaces__msg__heartbeat__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Heartbeat */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("zed_interfaces.msg._heartbeat");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Heartbeat");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  zed_interfaces__msg__Heartbeat * ros_message = (zed_interfaces__msg__Heartbeat *)raw_ros_message;
  {  // beat_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->beat_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "beat_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_ns
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->node_ns.data,
      strlen(ros_message->node_ns.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_ns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->node_name.data,
      strlen(ros_message->node_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // full_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->full_name.data,
      strlen(ros_message->full_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "full_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // camera_sn
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->camera_sn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "camera_sn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // svo_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->svo_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "svo_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // simul_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->simul_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "simul_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
