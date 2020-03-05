# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import openappwrapper_pb2 as openappwrapper__pb2


class OpenerStub(object):
  """The greeting service definition.
  """

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.Open = channel.unary_unary(
        '/openappwrapper.Opener/Open',
        request_serializer=openappwrapper__pb2.CommandRequest.SerializeToString,
        response_deserializer=openappwrapper__pb2.DebugReply.FromString,
        )
    self.ListenForContent = channel.unary_stream(
        '/openappwrapper.Opener/ListenForContent',
        request_serializer=openappwrapper__pb2.Id.SerializeToString,
        response_deserializer=openappwrapper__pb2.CommandRequest.FromString,
        )


class OpenerServicer(object):
  """The greeting service definition.
  """

  def Open(self, request, context):
    """Sends a greeting
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def ListenForContent(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_OpenerServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'Open': grpc.unary_unary_rpc_method_handler(
          servicer.Open,
          request_deserializer=openappwrapper__pb2.CommandRequest.FromString,
          response_serializer=openappwrapper__pb2.DebugReply.SerializeToString,
      ),
      'ListenForContent': grpc.unary_stream_rpc_method_handler(
          servicer.ListenForContent,
          request_deserializer=openappwrapper__pb2.Id.FromString,
          response_serializer=openappwrapper__pb2.CommandRequest.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'openappwrapper.Opener', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
