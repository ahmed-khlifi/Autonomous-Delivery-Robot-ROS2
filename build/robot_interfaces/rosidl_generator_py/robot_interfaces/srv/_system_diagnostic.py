# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/SystemDiagnostic.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SystemDiagnostic_Request(type):
    """Metaclass of message 'SystemDiagnostic_Request'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.SystemDiagnostic_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__system_diagnostic__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__system_diagnostic__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__system_diagnostic__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__system_diagnostic__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__system_diagnostic__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SystemDiagnostic_Request(metaclass=Metaclass_SystemDiagnostic_Request):
    """Message class 'SystemDiagnostic_Request'."""

    __slots__ = [
        '_full_report',
    ]

    _fields_and_field_types = {
        'full_report': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.full_report = kwargs.get('full_report', bool())

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
        if self.full_report != other.full_report:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def full_report(self):
        """Message field 'full_report'."""
        return self._full_report

    @full_report.setter
    def full_report(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'full_report' field must be of type 'bool'"
        self._full_report = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_SystemDiagnostic_Response(type):
    """Metaclass of message 'SystemDiagnostic_Response'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.SystemDiagnostic_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__system_diagnostic__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__system_diagnostic__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__system_diagnostic__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__system_diagnostic__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__system_diagnostic__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SystemDiagnostic_Response(metaclass=Metaclass_SystemDiagnostic_Response):
    """Message class 'SystemDiagnostic_Response'."""

    __slots__ = [
        '_system_ok',
        '_status_message',
        '_components',
        '_statuses',
        '_battery_level',
        '_error_count',
    ]

    _fields_and_field_types = {
        'system_ok': 'boolean',
        'status_message': 'string',
        'components': 'sequence<string>',
        'statuses': 'sequence<string>',
        'battery_level': 'float',
        'error_count': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.system_ok = kwargs.get('system_ok', bool())
        self.status_message = kwargs.get('status_message', str())
        self.components = kwargs.get('components', [])
        self.statuses = kwargs.get('statuses', [])
        self.battery_level = kwargs.get('battery_level', float())
        self.error_count = kwargs.get('error_count', int())

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
        if self.system_ok != other.system_ok:
            return False
        if self.status_message != other.status_message:
            return False
        if self.components != other.components:
            return False
        if self.statuses != other.statuses:
            return False
        if self.battery_level != other.battery_level:
            return False
        if self.error_count != other.error_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def system_ok(self):
        """Message field 'system_ok'."""
        return self._system_ok

    @system_ok.setter
    def system_ok(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'system_ok' field must be of type 'bool'"
        self._system_ok = value

    @builtins.property
    def status_message(self):
        """Message field 'status_message'."""
        return self._status_message

    @status_message.setter
    def status_message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status_message' field must be of type 'str'"
        self._status_message = value

    @builtins.property
    def components(self):
        """Message field 'components'."""
        return self._components

    @components.setter
    def components(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'components' field must be a set or sequence and each value of type 'str'"
        self._components = value

    @builtins.property
    def statuses(self):
        """Message field 'statuses'."""
        return self._statuses

    @statuses.setter
    def statuses(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'statuses' field must be a set or sequence and each value of type 'str'"
        self._statuses = value

    @builtins.property
    def battery_level(self):
        """Message field 'battery_level'."""
        return self._battery_level

    @battery_level.setter
    def battery_level(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_level' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'battery_level' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._battery_level = value

    @builtins.property
    def error_count(self):
        """Message field 'error_count'."""
        return self._error_count

    @error_count.setter
    def error_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'error_count' field must be an integer in [-2147483648, 2147483647]"
        self._error_count = value


class Metaclass_SystemDiagnostic(type):
    """Metaclass of service 'SystemDiagnostic'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.SystemDiagnostic')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__system_diagnostic

            from robot_interfaces.srv import _system_diagnostic
            if _system_diagnostic.Metaclass_SystemDiagnostic_Request._TYPE_SUPPORT is None:
                _system_diagnostic.Metaclass_SystemDiagnostic_Request.__import_type_support__()
            if _system_diagnostic.Metaclass_SystemDiagnostic_Response._TYPE_SUPPORT is None:
                _system_diagnostic.Metaclass_SystemDiagnostic_Response.__import_type_support__()


class SystemDiagnostic(metaclass=Metaclass_SystemDiagnostic):
    from robot_interfaces.srv._system_diagnostic import SystemDiagnostic_Request as Request
    from robot_interfaces.srv._system_diagnostic import SystemDiagnostic_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
