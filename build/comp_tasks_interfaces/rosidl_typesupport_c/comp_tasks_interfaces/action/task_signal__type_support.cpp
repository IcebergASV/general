// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
#include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_Goal_type_support_ids_t;

static const _TaskSignal_Goal_type_support_ids_t _TaskSignal_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_Goal_type_support_symbol_names_t _TaskSignal_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Goal)),
  }
};

typedef struct _TaskSignal_Goal_type_support_data_t
{
  void * data[2];
} _TaskSignal_Goal_type_support_data_t;

static _TaskSignal_Goal_type_support_data_t _TaskSignal_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_Goal_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_Goal)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_Result_type_support_ids_t;

static const _TaskSignal_Result_type_support_ids_t _TaskSignal_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_Result_type_support_symbol_names_t _TaskSignal_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Result)),
  }
};

typedef struct _TaskSignal_Result_type_support_data_t
{
  void * data[2];
} _TaskSignal_Result_type_support_data_t;

static _TaskSignal_Result_type_support_data_t _TaskSignal_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_Result_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_Result_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_Result_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_Result)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_Feedback_type_support_ids_t;

static const _TaskSignal_Feedback_type_support_ids_t _TaskSignal_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_Feedback_type_support_symbol_names_t _TaskSignal_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Feedback)),
  }
};

typedef struct _TaskSignal_Feedback_type_support_data_t
{
  void * data[2];
} _TaskSignal_Feedback_type_support_data_t;

static _TaskSignal_Feedback_type_support_data_t _TaskSignal_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_Feedback_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_Feedback)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_SendGoal_Request_type_support_ids_t;

static const _TaskSignal_SendGoal_Request_type_support_ids_t _TaskSignal_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_SendGoal_Request_type_support_symbol_names_t _TaskSignal_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)),
  }
};

typedef struct _TaskSignal_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _TaskSignal_SendGoal_Request_type_support_data_t;

static _TaskSignal_SendGoal_Request_type_support_data_t _TaskSignal_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_SendGoal_Request_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_SendGoal_Response_type_support_ids_t;

static const _TaskSignal_SendGoal_Response_type_support_ids_t _TaskSignal_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_SendGoal_Response_type_support_symbol_names_t _TaskSignal_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)),
  }
};

typedef struct _TaskSignal_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _TaskSignal_SendGoal_Response_type_support_data_t;

static _TaskSignal_SendGoal_Response_type_support_data_t _TaskSignal_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_SendGoal_Response_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_SendGoal_type_support_ids_t;

static const _TaskSignal_SendGoal_type_support_ids_t _TaskSignal_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_SendGoal_type_support_symbol_names_t _TaskSignal_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal)),
  }
};

typedef struct _TaskSignal_SendGoal_type_support_data_t
{
  void * data[2];
} _TaskSignal_SendGoal_type_support_data_t;

static _TaskSignal_SendGoal_type_support_data_t _TaskSignal_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_SendGoal_service_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TaskSignal_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_SendGoal)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_GetResult_Request_type_support_ids_t;

static const _TaskSignal_GetResult_Request_type_support_ids_t _TaskSignal_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_GetResult_Request_type_support_symbol_names_t _TaskSignal_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)),
  }
};

typedef struct _TaskSignal_GetResult_Request_type_support_data_t
{
  void * data[2];
} _TaskSignal_GetResult_Request_type_support_data_t;

static _TaskSignal_GetResult_Request_type_support_data_t _TaskSignal_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_GetResult_Request_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_GetResult_Response_type_support_ids_t;

static const _TaskSignal_GetResult_Response_type_support_ids_t _TaskSignal_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_GetResult_Response_type_support_symbol_names_t _TaskSignal_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)),
  }
};

typedef struct _TaskSignal_GetResult_Response_type_support_data_t
{
  void * data[2];
} _TaskSignal_GetResult_Response_type_support_data_t;

static _TaskSignal_GetResult_Response_type_support_data_t _TaskSignal_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_GetResult_Response_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_GetResult_type_support_ids_t;

static const _TaskSignal_GetResult_type_support_ids_t _TaskSignal_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_GetResult_type_support_symbol_names_t _TaskSignal_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult)),
  }
};

typedef struct _TaskSignal_GetResult_type_support_data_t
{
  void * data[2];
} _TaskSignal_GetResult_type_support_data_t;

static _TaskSignal_GetResult_type_support_data_t _TaskSignal_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_GetResult_service_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TaskSignal_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_GetResult)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace comp_tasks_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _TaskSignal_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSignal_FeedbackMessage_type_support_ids_t;

static const _TaskSignal_FeedbackMessage_type_support_ids_t _TaskSignal_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TaskSignal_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSignal_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSignal_FeedbackMessage_type_support_symbol_names_t _TaskSignal_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, action, TaskSignal_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_FeedbackMessage)),
  }
};

typedef struct _TaskSignal_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _TaskSignal_FeedbackMessage_type_support_data_t;

static _TaskSignal_FeedbackMessage_type_support_data_t _TaskSignal_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSignal_FeedbackMessage_message_typesupport_map = {
  2,
  "comp_tasks_interfaces",
  &_TaskSignal_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSignal_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSignal_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSignal_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSignal_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace comp_tasks_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_FeedbackMessage)() {
  return &::comp_tasks_interfaces::action::rosidl_typesupport_c::TaskSignal_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "comp_tasks_interfaces/action/task_signal.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__type_support.h"

static rosidl_action_type_support_t _comp_tasks_interfaces__action__TaskSignal__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal)()
{
  // Thread-safe by always writing the same values to the static struct
  _comp_tasks_interfaces__action__TaskSignal__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_SendGoal)();
  _comp_tasks_interfaces__action__TaskSignal__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_GetResult)();
  _comp_tasks_interfaces__action__TaskSignal__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _comp_tasks_interfaces__action__TaskSignal__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, comp_tasks_interfaces, action, TaskSignal_FeedbackMessage)();
  _comp_tasks_interfaces__action__TaskSignal__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_comp_tasks_interfaces__action__TaskSignal__typesupport_c;
}

#ifdef __cplusplus
}
#endif
