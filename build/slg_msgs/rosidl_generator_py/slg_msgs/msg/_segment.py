# generated from rosidl_generator_py/resource/_idl.py.em
# with input from slg_msgs:msg/Segment.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Segment(type):
    """Metaclass of message 'Segment'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'BACKGROUND': 0,
        'PERSON': 1,
        'PERSON_CANE': 2,
        'PERSON_WHEEL_CHAIR': 3,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('slg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'slg_msgs.msg.Segment')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__segment
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__segment
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__segment
            cls._TYPE_SUPPORT = module.type_support_msg__msg__segment
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__segment

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'BACKGROUND': cls.__constants['BACKGROUND'],
            'PERSON': cls.__constants['PERSON'],
            'PERSON_CANE': cls.__constants['PERSON_CANE'],
            'PERSON_WHEEL_CHAIR': cls.__constants['PERSON_WHEEL_CHAIR'],
            'ID__DEFAULT': 0,
            'LABEL__DEFAULT': 0,
            'ANGULAR_DISTANCE__DEFAULT': 0.0,
        }

    @property
    def BACKGROUND(self):
        """Message constant 'BACKGROUND'."""
        return Metaclass_Segment.__constants['BACKGROUND']

    @property
    def PERSON(self):
        """Message constant 'PERSON'."""
        return Metaclass_Segment.__constants['PERSON']

    @property
    def PERSON_CANE(self):
        """Message constant 'PERSON_CANE'."""
        return Metaclass_Segment.__constants['PERSON_CANE']

    @property
    def PERSON_WHEEL_CHAIR(self):
        """Message constant 'PERSON_WHEEL_CHAIR'."""
        return Metaclass_Segment.__constants['PERSON_WHEEL_CHAIR']

    @property
    def ID__DEFAULT(cls):
        """Return default value for message field 'id'."""
        return 0

    @property
    def LABEL__DEFAULT(cls):
        """Return default value for message field 'label'."""
        return 0

    @property
    def ANGULAR_DISTANCE__DEFAULT(cls):
        """Return default value for message field 'angular_distance'."""
        return 0.0


class Segment(metaclass=Metaclass_Segment):
    """
    Message class 'Segment'.

    Constants:
      BACKGROUND
      PERSON
      PERSON_CANE
      PERSON_WHEEL_CHAIR
    """

    __slots__ = [
        '_id',
        '_label',
        '_angular_distance',
        '_last_point_prior_segment',
        '_first_point_next_segment',
        '_points',
    ]

    _fields_and_field_types = {
        'id': 'uint64',
        'label': 'uint32',
        'angular_distance': 'double',
        'last_point_prior_segment': 'geometry_msgs/Point',
        'first_point_next_segment': 'geometry_msgs/Point',
        'points': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get(
            'id', Segment.ID__DEFAULT)
        self.label = kwargs.get(
            'label', Segment.LABEL__DEFAULT)
        self.angular_distance = kwargs.get(
            'angular_distance', Segment.ANGULAR_DISTANCE__DEFAULT)
        from geometry_msgs.msg import Point
        self.last_point_prior_segment = kwargs.get('last_point_prior_segment', Point())
        from geometry_msgs.msg import Point
        self.first_point_next_segment = kwargs.get('first_point_next_segment', Point())
        self.points = kwargs.get('points', [])

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
        if self.id != other.id:
            return False
        if self.label != other.label:
            return False
        if self.angular_distance != other.angular_distance:
            return False
        if self.last_point_prior_segment != other.last_point_prior_segment:
            return False
        if self.first_point_next_segment != other.first_point_next_segment:
            return False
        if self.points != other.points:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._id = value

    @builtins.property
    def label(self):
        """Message field 'label'."""
        return self._label

    @label.setter
    def label(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'label' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'label' field must be an unsigned integer in [0, 4294967295]"
        self._label = value

    @builtins.property
    def angular_distance(self):
        """Message field 'angular_distance'."""
        return self._angular_distance

    @angular_distance.setter
    def angular_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angular_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'angular_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._angular_distance = value

    @builtins.property
    def last_point_prior_segment(self):
        """Message field 'last_point_prior_segment'."""
        return self._last_point_prior_segment

    @last_point_prior_segment.setter
    def last_point_prior_segment(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'last_point_prior_segment' field must be a sub message of type 'Point'"
        self._last_point_prior_segment = value

    @builtins.property
    def first_point_next_segment(self):
        """Message field 'first_point_next_segment'."""
        return self._first_point_next_segment

    @first_point_next_segment.setter
    def first_point_next_segment(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'first_point_next_segment' field must be a sub message of type 'Point'"
        self._first_point_next_segment = value

    @builtins.property
    def points(self):
        """Message field 'points'."""
        return self._points

    @points.setter
    def points(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'points' field must be a set or sequence and each value of type 'Point'"
        self._points = value
