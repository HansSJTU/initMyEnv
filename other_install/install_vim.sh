#! /bin/bash
#
# install_vim.sh
# Copyright (C) 2017-09-05 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

user_name="$1"
user_mail="$2"

if [ ! -d ~/.vim_runtime ]; then
    echo "Start to Setting Up Vim..."
    git clone --depth=1 -b google https://github.com/HansSJTU/vimrc ~/.vim_runtime
    bash ~/.vim_runtime/install_awesome_vimrc.sh
else
    echo "Updating Vim..."
    pushd ~/.vim_runtime > /dev/null
    git fetch
    git checkout google
    git pull origin google
    popd > /dev/null
fi

#set up vim-template
if [[ -z ${user_name} || -z ${user_mail} ]]; then
    :;
else
    pushd ~/.vim_runtime/sources_forked/vim-template/templates > /dev/null
    sed -i "s?%DATE%?%DATE%?g;s?%MAIL%?${user_mail}?g;s?%USER%?${user_name}?g;s?YEAR?DATE?g" *
    popd > /dev/null
fi
