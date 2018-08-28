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
	apt-get install python-pip python-dev build-essential
	pip install --upgrade pip
	pip install --upgrade virtualenv
fi
