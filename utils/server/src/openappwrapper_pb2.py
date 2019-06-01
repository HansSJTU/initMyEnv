# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: openappwrapper.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='openappwrapper.proto',
  package='openappwrapper',
  syntax='proto3',
  serialized_options=_b('\242\002\003HLW'),
  serialized_pb=_b('\n\x14openappwrapper.proto\x12\x0eopenappwrapper\"!\n\x0e\x43ommandRequest\x12\x0f\n\x07\x63ommand\x18\x01 \x01(\t\"\x1d\n\nDebugReply\x12\x0f\n\x07message\x18\x01 \x01(\t2N\n\x06Opener\x12\x44\n\x04Open\x12\x1e.openappwrapper.CommandRequest\x1a\x1a.openappwrapper.DebugReply\"\x00\x42\x06\xa2\x02\x03HLWb\x06proto3')
)




_COMMANDREQUEST = _descriptor.Descriptor(
  name='CommandRequest',
  full_name='openappwrapper.CommandRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='command', full_name='openappwrapper.CommandRequest.command', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=40,
  serialized_end=73,
)


_DEBUGREPLY = _descriptor.Descriptor(
  name='DebugReply',
  full_name='openappwrapper.DebugReply',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='message', full_name='openappwrapper.DebugReply.message', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=75,
  serialized_end=104,
)

DESCRIPTOR.message_types_by_name['CommandRequest'] = _COMMANDREQUEST
DESCRIPTOR.message_types_by_name['DebugReply'] = _DEBUGREPLY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

CommandRequest = _reflection.GeneratedProtocolMessageType('CommandRequest', (_message.Message,), dict(
  DESCRIPTOR = _COMMANDREQUEST,
  __module__ = 'openappwrapper_pb2'
  # @@protoc_insertion_point(class_scope:openappwrapper.CommandRequest)
  ))
_sym_db.RegisterMessage(CommandRequest)

DebugReply = _reflection.GeneratedProtocolMessageType('DebugReply', (_message.Message,), dict(
  DESCRIPTOR = _DEBUGREPLY,
  __module__ = 'openappwrapper_pb2'
  # @@protoc_insertion_point(class_scope:openappwrapper.DebugReply)
  ))
_sym_db.RegisterMessage(DebugReply)


DESCRIPTOR._options = None

_OPENER = _descriptor.ServiceDescriptor(
  name='Opener',
  full_name='openappwrapper.Opener',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=106,
  serialized_end=184,
  methods=[
  _descriptor.MethodDescriptor(
    name='Open',
    full_name='openappwrapper.Opener.Open',
    index=0,
    containing_service=None,
    input_type=_COMMANDREQUEST,
    output_type=_DEBUGREPLY,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_OPENER)

DESCRIPTOR.services_by_name['Opener'] = _OPENER

# @@protoc_insertion_point(module_scope)
