# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yolov8_msgs:msg/IcebergDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IcebergDetection(type):
    """Metaclass of message 'IcebergDetection'."""

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
            module = import_type_support('yolov8_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yolov8_msgs.msg.IcebergDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__iceberg_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__iceberg_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__iceberg_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__iceberg_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__iceberg_detection

            from yolov8_msgs.msg import IcebergBoundingBox2D
            if IcebergBoundingBox2D.__class__._TYPE_SUPPORT is None:
                IcebergBoundingBox2D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IcebergDetection(metaclass=Metaclass_IcebergDetection):
    """Message class 'IcebergDetection'."""

    __slots__ = [
        '_class_id',
        '_class_name',
        '_score',
        '_bbox',
    ]

    _fields_and_field_types = {
        'class_id': 'int32',
        'class_name': 'string',
        'score': 'double',
        'bbox': 'yolov8_msgs/IcebergBoundingBox2D',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['yolov8_msgs', 'msg'], 'IcebergBoundingBox2D'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.class_id = kwargs.get('class_id', int())
        self.class_name = kwargs.get('class_name', str())
        self.score = kwargs.get('score', float())
        from yolov8_msgs.msg import IcebergBoundingBox2D
        self.bbox = kwargs.get('bbox', IcebergBoundingBox2D())

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
        if self.class_id != other.class_id:
            return False
        if self.class_name != other.class_name:
            return False
        if self.score != other.score:
            return False
        if self.bbox != other.bbox:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def class_id(self):
        """Message field 'class_id'."""
        return self._class_id

    @class_id.setter
    def class_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'class_id' field must be an integer in [-2147483648, 2147483647]"
        self._class_id = value

    @builtins.property
    def class_name(self):
        """Message field 'class_name'."""
        return self._class_name

    @class_name.setter
    def class_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'class_name' field must be of type 'str'"
        self._class_name = value

    @builtins.property
    def score(self):
        """Message field 'score'."""
        return self._score

    @score.setter
    def score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'score' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'score' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._score = value

    @builtins.property
    def bbox(self):
        """Message field 'bbox'."""
        return self._bbox

    @bbox.setter
    def bbox(self, value):
        if __debug__:
            from yolov8_msgs.msg import IcebergBoundingBox2D
            assert \
                isinstance(value, IcebergBoundingBox2D), \
                "The 'bbox' field must be a sub message of type 'IcebergBoundingBox2D'"
        self._bbox = value
