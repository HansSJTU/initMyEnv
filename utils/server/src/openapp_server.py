#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright 2015 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""The Python implementation of the GRPC helloworld.Greeter server."""

from concurrent import futures
import time
import logging
import os

import grpc

import openappwrapper_pb2
import openappwrapper_pb2_grpc

_ONE_DAY_IN_SECONDS = 60 * 60 * 24

DEBUG_CHANNEL = '[::]:50051'
REAL_CHANNEL = '[::]:9100'

channel = DEBUG_CHANNEL

class Opener(openappwrapper_pb2_grpc.OpenerServicer):
    def __init__(self):
        self.command_queue = []

    """
    # Direct Connect Mode.
    def Open(self, request, context):
        if request.mode == 'open':
            command = "open " + request.command
            os.system(command)
            message = '[Done]: ' + command
        elif request.mode == 'copy':
            command = "echo \"" + request.command + "\" | tr -d '\n' | pbcopy "
            os.system(command)
            message = '[Done]: ' + command
        else:
            message = '[Failed]: ' + request.mode + ' ' + request.command
        message = message.replace('\n', '\ n')
        logging.warning(message)
        return openappwrapper_pb2.DebugReply(message=message)
    """

    def Open(self, request, context):
        print('Command Received: {com}'.format(com=str(request)))
        self.command_queue.append(request)
        return openappwrapper_pb2.DebugReply(message='RPC SUC')

    def ListenForContent(self, request, context):
        print('Start Listening for Machine: ' + request.machine_name)
        # Flush current pool
        print('--------- FLUSHING ---------')
        print(self.command_queue)
        self.command_queue = []
        print('--------- DONE ---------')

        lastindex = 0
        while True:
            time.sleep(1)
            while len(self.command_queue) > lastindex:
                content = self.command_queue[lastindex]
                lastindex += 1
                yield content

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=20))
    openappwrapper_pb2_grpc.add_OpenerServicer_to_server(Opener(), server)
    server.add_insecure_port(channel)
    server.start()
    try:
        while True:
            time.sleep(_ONE_DAY_IN_SECONDS)
    except KeyboardInterrupt:
        server.stop(0)


if __name__ == '__main__':
    logging.basicConfig()
    serve()
