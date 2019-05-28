#! /bin/bash
#
# install_vim.sh
# Copyright (C) 2017-09-05 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

if [[ ! -d ~/.vim_runtime ]]; then
    echo "Start to Setting Up Vim..."
    git clone -b taoxuy https://github.com/TAOXUY/vimrc.git ~/.vim_runtime
    bash ~/.vim_runtime/install_awesome_vimrc.sh
fi


vim + PlugInstall +qall
vim + PluginInstall +qall

if [[ ! -d ~/.vim_runtime/sources_forked/YouCompleteMe ]]; then
  echo "Setting up YCM..."
  git clone https://github.com/Valloric/YouCompleteMe.git ~/.vim_runtime/sources_forked/YouCompleteMe
  pushd ~/.vim_runtime/sources_forked/YouCompleteMe
  git submodule update --init --recursive
  python install.py --go-completer --clang-completer
  popd
fi

