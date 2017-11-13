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
    git clone --depth=1 https://github.com/HansSJTU/vimrc ~/.vim_runtime
    bash ~/.vim_runtime/install_awesome_vimrc.sh
fi

#set up vim-template
if [[ -z ${user_name} || -z ${user_mail} ]]; then
    :;
else
    pushd ~/.vim_runtime/sources_forked/vim-template/templates > /dev/null
    sed -i "s?%DATE%?%DATE%?g;s?%MAIL%?${user_mail}?g;s?%USER%?${user_name}?g;s?YEAR?DATE?g" *
    popd > /dev/null
fi
