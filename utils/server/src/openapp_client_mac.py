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

import signal
import os
import grpc
import sys
import time

import openappwrapper_pb2
import openappwrapper_pb2_grpc

DEBUG_CHANNEL = 'localhost:50051'
REAL_CHANNEL = '73.231.57.242:9050'
MACHINE_ID = 'hanxiao_corp_mac'

channel = DEBUG_CHANNEL

"""
def run(mode, command):
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    with grpc.insecure_channel(channel) as ch:
        stub = openappwrapper_pb2_grpc.OpenerStub(ch)
        response = stub.Open(openappwrapper_pb2.Commandcommand(command=command, mode=mode))
    print(response.message)
"""

def run():
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    with grpc.insecure_channel(channel) as ch:
        stub = openappwrapper_pb2_grpc.OpenerStub(ch)
        result_generator = stub.ListenForContent(openappwrapper_pb2.Id(machine_name=MACHINE_ID))
        def close_ch(signalNumber, frame):
            print('Receive Terminating...')
            result_generator.cancel()
            sys.exit(0)
        signal.signal(signal.SIGINT, close_ch)
        for command in result_generator:
            if command.mode == 'open':
                command = "open " + command.command
                os.system(command)
                message = '[Done]: ' + command
            elif command.mode == 'copy':
                command = "echo \"" + command.command + "\" | tr -d '\n' | pbcopy "
                os.system(command)
                message = '[Done]: ' + command
            else:
                message = '[Failed]: ' + command.mode + ' ' + command.command
            message = message.replace('\n', '\ n')
            logging.warning(message)

if __name__ == '__main__':
    logging.basicConfig()
    run()
