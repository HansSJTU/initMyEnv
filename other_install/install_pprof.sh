#! /bin/bash
#
# install_pprof.sh
# Copyright (C) 2018-02-24 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#


if [ "$(uname)" == "Darwin" ]; then
    brew install go
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    sudo apt-get install golang
fi

gp="~/.mygo"
if [ ! -d ~/.mygo ]; then
    mkdir -p ~/.mygo
fi
gp_real=`realpath ~/.mygo`
export GOPATH=${gp_real}
# set new pprop
if [ ! -f ${gp_real}/bin/pprof ]; then
    go get github.com/google/pprof
    sudo ln -s ${gp_real}/bin/pprof /usr/local/bin/pprof-new
fi
