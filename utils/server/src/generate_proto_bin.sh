#! /bin/bash
#
# generate_proto_bin.sh
# Copyright (C) 2019-06-01 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#


python -m grpc_tools.protoc -I../proto --python_out=. --grpc_python_out=. ../proto/openappwrapper.proto
