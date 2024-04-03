# generated from rosidl_generator_py/resource/_idl.py.em
# with input from zed_interfaces:msg/Keypoint2Df.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'kp'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Keypoint2Df(type):
    """Metaclass of message 'Keypoint2Df'."""

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
            module = import_type_support('zed_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zed_interfaces.msg.Keypoint2Df')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__keypoint2_df
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__keypoint2_df
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__keypoint2_df
            cls._TYPE_SUPPORT = module.type_support_msg__msg__keypoint2_df
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__keypoint2_df

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Keypoint2Df(metaclass=Metaclass_Keypoint2Df):
    """Message class 'Keypoint2Df'."""

    __slots__ = [
        '_kp',
    ]

    _fields_and_field_types = {
        'kp': 'float[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'kp' not in kwargs:
            self.kp = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.kp = numpy.array(kwargs.get('kp'), dtype=numpy.float32)
            assert self.kp.shape == (2, )

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
        if all(self.kp != other.kp):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def kp(self):
        """Message field 'kp'."""
        return self._kp

    @kp.setter
    def kp(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'kp' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'kp' numpy.ndarray() must have a size of 2"
            self._kp = value
            return
        if __debug__:
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'kp' field must be a set or sequence with length 2 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._kp = numpy.array(value, dtype=numpy.float32)
