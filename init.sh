#!/bin/bash
version="v1.0"

if [ -f ~/.bashrc ]; then
    v_curr=`head -1 ~/.bashrc | awk '{print $3}'`
    if [ ${v_curr} != ${version} ]; then
        mv ~/.bashrc ~/.bashrc.old
        cp configs/bashrc ~/.bashrc
    fi
else
    cp configs/bashrc ~/.bashrc
fi

if [ -f ~/.tmux.conf ]; then
    v_curr=`head -1 ~/.tmux.conf | awk '{print $3}'`
    if [ ${v_curr} != ${version} ]; then
        mv ~/.tmux.conf ~/.tmux.conf.old
        cp configs/tmux.conf ~/.tmux.conf
    fi
else
    cp configs/tmux.conf ~/.tmux.conf
fi

v_flag=0;
if [ -f ~/.vimrc ]; then
    v_cur_num=`head -1 ~/.vimrc | awk '{print NF}'`
    if [ ${v_cur_num} -lt 3 ]; then
        mv ~/.vimrc ~/.vimrc.old
    else
        v_curr=`head -1 ~/.vimrc | awk '{print $3}'`
        echo ${v_curr}
        if [ ${v_curr} != ${version} ]; then
            mv ~/.vimrc ~/.vimrc.old
        else
            v_flag=1
        fi
    fi
fi

if [ ! -d ~/.vim_runtime ]; then
    git clone https://github.com/amix/vimrc.git ~/.vim_runtime
    bash ~/.vim_runtime/install_awesome_vimrc.sh
    cp configs/my_configs.vim ~/.vim_runtime/
    sed -e '1i\'$'\n''# hanxiao v${version}' ~/.vimrc > tmp
    mv tmp ~/.vimrc
elif [ ${v_flag} -eq 0 ]; then
    cp configs/my_configs.vim ~/.vim_runtime/
    sed -e '1i\'$'\n''\" hanxiao v${version}' ~/.vimrc > tmp
    mv tmp ~/.vimrc
fi

echo "done"

