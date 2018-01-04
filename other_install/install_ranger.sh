#! /bin/bash
#
# install_rancher.sh
# Copyright (C) 2018-01-03 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

if [ "$(uname)" == "Darwin" ]; then
    brew install ranger
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    sudo apt-get install ranger
fi

ranger --copy-config=scope

if [ "$(uname)" == "Darwin" ]; then
    brew install atool
    brew install highlight
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    sudo apt-get install lynx
    sudo apt-get install elinks
    sudo apt-get install highlight
    sudo apt-get install img2txt
    sudo apt-get install atool
    sudo apt-get install pdftotext
    sudo apt-get install mediainfo
fi
