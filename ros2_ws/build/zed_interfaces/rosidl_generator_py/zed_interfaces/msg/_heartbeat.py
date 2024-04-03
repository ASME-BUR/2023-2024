# generated from rosidl_generator_py/resource/_idl.py.em
# with input from zed_interfaces:msg/Heartbeat.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Heartbeat(type):
    """Metaclass of message 'Heartbeat'."""

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
                'zed_interfaces.msg.Heartbeat')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__heartbeat
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__heartbeat
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__heartbeat
            cls._TYPE_SUPPORT = module.type_support_msg__msg__heartbeat
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__heartbeat

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Heartbeat(metaclass=Metaclass_Heartbeat):
    """Message class 'Heartbeat'."""

    __slots__ = [
        '_beat_count',
        '_node_ns',
        '_node_name',
        '_full_name',
        '_camera_sn',
        '_svo_mode',
        '_simul_mode',
    ]

    _fields_and_field_types = {
        'beat_count': 'uint64',
        'node_ns': 'string',
        'node_name': 'string',
        'full_name': 'string',
        'camera_sn': 'uint32',
        'svo_mode': 'boolean',
        'simul_mode': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.beat_count = kwargs.get('beat_count', int())
        self.node_ns = kwargs.get('node_ns', str())
        self.node_name = kwargs.get('node_name', str())
        self.full_name = kwargs.get('full_name', str())
        self.camera_sn = kwargs.get('camera_sn', int())
        self.svo_mode = kwargs.get('svo_mode', bool())
        self.simul_mode = kwargs.get('simul_mode', bool())

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
        if self.beat_count != other.beat_count:
            return False
        if self.node_ns != other.node_ns:
            return False
        if self.node_name != other.node_name:
            return False
        if self.full_name != other.full_name:
            return False
        if self.camera_sn != other.camera_sn:
            return False
        if self.svo_mode != other.svo_mode:
            return False
        if self.simul_mode != other.simul_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def beat_count(self):
        """Message field 'beat_count'."""
        return self._beat_count

    @beat_count.setter
    def beat_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'beat_count' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'beat_count' field must be an unsigned integer in [0, 18446744073709551615]"
        self._beat_count = value

    @builtins.property
    def node_ns(self):
        """Message field 'node_ns'."""
        return self._node_ns

    @node_ns.setter
    def node_ns(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_ns' field must be of type 'str'"
        self._node_ns = value

    @builtins.property
    def node_name(self):
        """Message field 'node_name'."""
        return self._node_name

    @node_name.setter
    def node_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_name' field must be of type 'str'"
        self._node_name = value

    @builtins.property
    def full_name(self):
        """Message field 'full_name'."""
        return self._full_name

    @full_name.setter
    def full_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'full_name' field must be of type 'str'"
        self._full_name = value

    @builtins.property
    def camera_sn(self):
        """Message field 'camera_sn'."""
        return self._camera_sn

    @camera_sn.setter
    def camera_sn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'camera_sn' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'camera_sn' field must be an unsigned integer in [0, 4294967295]"
        self._camera_sn = value

    @builtins.property
    def svo_mode(self):
        """Message field 'svo_mode'."""
        return self._svo_mode

    @svo_mode.setter
    def svo_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'svo_mode' field must be of type 'bool'"
        self._svo_mode = value

    @builtins.property
    def simul_mode(self):
        """Message field 'simul_mode'."""
        return self._simul_mode

    @simul_mode.setter
    def simul_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'simul_mode' field must be of type 'bool'"
        self._simul_mode = value
