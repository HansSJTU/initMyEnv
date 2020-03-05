#! /bin/bash
#
# install_tpm.sh
# Copyright (C) 2019-10-11 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

if [ ! -d ~/.tmux/plugins/tpm ]; then
    echo "Start to Setting Up tpm..."
    git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm
else
    echo "Updating tpm..."
    pushd ~/.tmux/plugins/tpm > /dev/null
    git pull origin master
    popd > /dev/null
fi
