# generated from rosidl_generator_py/resource/_idl.py.em
# with input from comp_tasks_interfaces:msg/StartTask.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StartTask(type):
    """Metaclass of message 'StartTask'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('comp_tasks_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'comp_tasks_interfaces.msg.StartTask')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__start_task
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__start_task
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__start_task
            cls._TYPE_SUPPORT = module.type_support_msg__msg__start_task
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__start_task

            from comp_tasks_interfaces.msg import Task
            if Task.__class__._TYPE_SUPPORT is None:
                Task.__class__.__import_type_support__()

            from geographic_msgs.msg import GeoPoint
            if GeoPoint.__class__._TYPE_SUPPORT is None:
                GeoPoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartTask(metaclass=Metaclass_StartTask):
    """Message class 'StartTask'."""

    __slots__ = [
        '_task',
        '_start_pnt',
        '_finish_pnt',
    ]

    _fields_and_field_types = {
        'task': 'comp_tasks_interfaces/Task',
        'start_pnt': 'geographic_msgs/GeoPoint',
        'finish_pnt': 'geographic_msgs/GeoPoint',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['comp_tasks_interfaces', 'msg'], 'Task'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geographic_msgs', 'msg'], 'GeoPoint'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geographic_msgs', 'msg'], 'GeoPoint'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from comp_tasks_interfaces.msg import Task
        self.task = kwargs.get('task', Task())
        from geographic_msgs.msg import GeoPoint
        self.start_pnt = kwargs.get('start_pnt', GeoPoint())
        from geographic_msgs.msg import GeoPoint
        self.finish_pnt = kwargs.get('finish_pnt', GeoPoint())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.task != other.task:
            return False
        if self.start_pnt != other.start_pnt:
            return False
        if self.finish_pnt != other.finish_pnt:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task(self):
        """Message field 'task'."""
        return self._task

    @task.setter
    def task(self, value):
        if __debug__:
            from comp_tasks_interfaces.msg import Task
            assert \
                isinstance(value, Task), \
                "The 'task' field must be a sub message of type 'Task'"
        self._task = value

    @builtins.property
    def start_pnt(self):
        """Message field 'start_pnt'."""
        return self._start_pnt

    @start_pnt.setter
    def start_pnt(self, value):
        if __debug__:
            from geographic_msgs.msg import GeoPoint
            assert \
                isinstance(value, GeoPoint), \
                "The 'start_pnt' field must be a sub message of type 'GeoPoint'"
        self._start_pnt = value

    @builtins.property
    def finish_pnt(self):
        """Message field 'finish_pnt'."""
        return self._finish_pnt

    @finish_pnt.setter
    def finish_pnt(self, value):
        if __debug__:
            from geographic_msgs.msg import GeoPoint
            assert \
                isinstance(value, GeoPoint), \
                "The 'finish_pnt' field must be a sub message of type 'GeoPoint'"
        self._finish_pnt = value
