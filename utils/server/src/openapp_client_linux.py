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
"""The Python implementation of the GRPC helloworld.Greeter client."""

from __future__ import print_function
import logging

import grpc
import sys

import openappwrapper_pb2
import openappwrapper_pb2_grpc

DEBUG_CHANNEL = 'localhost:50051'
REAL_CHANNEL = '73.231.57.242:9050'

channel = DEBUG_CHANNEL

def run(mode, command):
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    try:
        with grpc.insecure_channel(channel) as ch:
            stub = openappwrapper_pb2_grpc.OpenerStub(ch)
            response = stub.Open(openappwrapper_pb2.CommandRequest(command=command, mode=mode))
        print(response.message)
    except KeyboardInterrupt:
        logging.warning('User Exit...')


if __name__ == '__main__':
    logging.basicConfig()
    mode = sys.argv[1]
    command = sys.argv[2]
    run(mode, command)
