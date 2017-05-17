#!/bin/bash
version="v1.0"

source ./configs/bash_alias
source ./configs/bash_func
# Define OS specific downloads
if [ "$(uname)" == "Darwin" ]; then
    echo "${green}[Operation System Detect]${endcolor} Mac OSX "
    plugin_file="./configs/install.mac"
    os_name="OSX"
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "${green}[Operation System Detect]${endcolor} Linux "
    plugin_file="./configs/install.linux"
    os_name="Linux"
    sudo apt-get update
else
    echo "${red}[Error]${endcolor} Unkown Operation System! "
    echo "This init script only support Mac OSX and Linux! "
EOF
fi

function install_plugins
{
    if [ $1 == "OSX" ]; then
        brew install "$2"
    elif [ $1 == "Linux" ]; then
        sudo apt-get install "$2"
    fi
}

total_plugin_num=`cat ${plugin_file} | wc -l`
current_plugin_num=1
while read line; do
    echo "${green}[${current_plugin_num} / ${total_plugin_num}] ${endcolor} : ${line}..."
    ((current_plugin_num++))
    install_plugins ${os_name} ${line}
done < ${plugin_file}
echo "${grenn}[FINISHED]${endcolor} done installing! "

if [ -f ~/.bash_alias ]; then
    backup ~/.bash_alias
fi
cp ./configs/bash_alias ~/.bash_alias

if [ -f ~/.bash_func ]; then
    backup ~/.bash_func
fi
cp ./configs/bash_func ~/.bash_func

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
    sed -e '1i\'$'\n''\" hanxiao v${version}' ~/.vimrc > tmp
    mv tmp ~/.vimrc
elif [ ${v_flag} -eq 0 ]; then
    cp configs/my_configs.vim ~/.vim_runtime/
    sed -e '1i\'$'\n''\" hanxiao v${version}' ~/.vimrc > tmp
    mv tmp ~/.vimrc
fi

if [ -d ~/.vim_runtime/sources_forked/vim-peepopen ]; then
    rm -rf ~/.vim_runtime/sources_forked/vim-peepopen
fi

echo "done"

