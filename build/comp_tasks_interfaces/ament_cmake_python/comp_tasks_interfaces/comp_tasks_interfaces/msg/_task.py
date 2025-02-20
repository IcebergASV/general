# generated from rosidl_generator_py/resource/_idl.py.em
# with input from comp_tasks_interfaces:msg/Task.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Task(type):
    """Metaclass of message 'Task'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TASK_NOT_SET': 0,
        'MANEUVERING': 1,
        'NAVIGATION': 2,
        'COLLISION_AVOIDANCE': 3,
        'DOCKING': 4,
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
                'comp_tasks_interfaces.msg.Task')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__task
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__task
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__task
            cls._TYPE_SUPPORT = module.type_support_msg__msg__task
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__task

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TASK_NOT_SET': cls.__constants['TASK_NOT_SET'],
            'MANEUVERING': cls.__constants['MANEUVERING'],
            'NAVIGATION': cls.__constants['NAVIGATION'],
            'COLLISION_AVOIDANCE': cls.__constants['COLLISION_AVOIDANCE'],
            'DOCKING': cls.__constants['DOCKING'],
        }

    @property
    def TASK_NOT_SET(self):
        """Message constant 'TASK_NOT_SET'."""
        return Metaclass_Task.__constants['TASK_NOT_SET']

    @property
    def MANEUVERING(self):
        """Message constant 'MANEUVERING'."""
        return Metaclass_Task.__constants['MANEUVERING']

    @property
    def NAVIGATION(self):
        """Message constant 'NAVIGATION'."""
        return Metaclass_Task.__constants['NAVIGATION']

    @property
    def COLLISION_AVOIDANCE(self):
        """Message constant 'COLLISION_AVOIDANCE'."""
        return Metaclass_Task.__constants['COLLISION_AVOIDANCE']

    @property
    def DOCKING(self):
        """Message constant 'DOCKING'."""
        return Metaclass_Task.__constants['DOCKING']


class Task(metaclass=Metaclass_Task):
    """
    Message class 'Task'.

    Constants:
      TASK_NOT_SET
      MANEUVERING
      NAVIGATION
      COLLISION_AVOIDANCE
      DOCKING
    """

    __slots__ = [
        '_current_task',
    ]

    _fields_and_field_types = {
        'current_task': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_task = kwargs.get('current_task', int())

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
        if self.current_task != other.current_task:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_task(self):
        """Message field 'current_task'."""
        return self._current_task

    @current_task.setter
    def current_task(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_task' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'current_task' field must be an unsigned integer in [0, 255]"
        self._current_task = value
