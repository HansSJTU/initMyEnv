#! /bin/bash
#
# switch_xsel.sh
# Copyright (C) 2018-07-09 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

sed -i "s@xsel -bi@xsel@g" ~/.tmux.conf
sed -i "s@xsel -bi@xsel@g" ~/.vim_runtime/my_configs.vim
sed -i "s@xsel -bi@xsel@g" ~/.bash_func

sed -i "s@xsel@xsel -bi@g" ~/.tmux.conf
sed -i "s@xsel@xsel -bi@g" ~/.vim_runtime/my_configs.vim
sed -i "s@xsel@xsel -bi@g" ~/.bash_func

sed -i "s@!open@!xdg-open@g" ~/.vim_runtime/my_configs.vim
