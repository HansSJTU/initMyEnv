#! /bin/bash
#
# install_grpc.sh
# Copyright (C) 2019-06-01 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

# https://grpc.io/docs/quickstart/python/

python -m pip3 install --upgrade pip --user
python -m pip3 install grpcio --user
python -m pip3 install grpcio-tools --user
