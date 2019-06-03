#! /bin/bash
#
# install_pip.sh
# Copyright (C) 2017-11-23 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

if [ "$(uname)" == "Darwin" ]; then
	sudo easy_install pip
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  apt update
  apt-get install python3-pip python3-dev build-essential cmake
  pip3 install --upgrade pip
  pip3 install --upgrade virtualenv
  pip3 install --user yapf
fi
