#!/bin/bash
version="v1.0"

if [[ ! $1 = "-a" ]]; then
    read -p "Your Name: " user_name
    read -p "Your Mail(Errors when \"?\" in your mail): " user_mail
    read -p "Your Git Name: " git_name
    read -p "Your Git Mail: " git_email
else
    user_name="Hanxiao"
    user_mail="hah114@ucsd.edu"
    git_name="HansSJTU"
    git_email="Hanshosjtu@gmail.com"
fi
read -sp "Your Git Password: " git_passwd
echo -ne "\n"

shopt -s expand_aliases
source ./configs/bash_alias
source ./configs/bash_func

# Define OS specific downloads
if [ "$(uname)" == "Darwin" ]; then
    echo "${green}[Operation System Detect]${endcolor} Mac OSX "
    plugin_file="./configs/install.mac"
    os_name="OSX"
    sudo easy_install pip
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "${green}[Operation System Detect]${endcolor} Linux "
    plugin_file="./configs/install.linux"
    os_name="Linux"
    echo "${orange}Start to Update apt-get...${endcolor}"
    sudo apt-get update
    echo "${orange}Start to Setup Color Theme...${endcolor}"
    wget -O xt  http://git.io/v3D8e && chmod +x xt && ./xt && rm xt
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
        wait
    fi
}

echo "${orange}Start to Install Plugins...${endcolor}"
total_plugin_num=`cat ${plugin_file} | wc -l`
current_plugin_num=1
all_plugin=""
for plugin in `cat ${plugin_file}`; do
    echo "${green}[${current_plugin_num} / ${total_plugin_num}] ${endcolor} : ${plugin}..."
    ((current_plugin_num++))
    install_plugins ${os_name} ${plugin}
done

echo "${green}[FINISHED]${endcolor} done installing! "

if [ ! -d ~/.setting_backup ]; then
    mkdir ~/.setting_backup
fi

function backup_and_copy
{
    if [ -f "$1" ]; then
        backup "$1"
        mv ${backup_file_dir} ~/.setting_backup/
    fi
}

backup_and_copy ~/.bash_alias
backup_and_copy ~/.bashrc
backup_and_copy ~/.tmux.conf
backup_and_copy ~/.vimrc
backup_and_copy ~/.gitconfig
backup_and_copy ~/.bash_profile
backup_and_copy ~/Library/Preferences/com.apple.Terminal.plist #terminal theme binary config

if [ ! -d ~/.vim_runtime ]; then
    echo "${orange}Start to Setting Up Vim...${endcolor}"
    git clone --depth=1 https://github.com/amix/vimrc.git ~/.vim_runtime
    bash ~/.vim_runtime/install_awesome_vimrc.sh
    # ignore this map in old basic.vim
    sed -i "s@map <space> /@\" map <space> /@" ~/.vim_runtime/vimrcs/basic.vim
fi

if [ -d ~/.vim_runtime/sources_forked/vim-peepopen ]; then
    rm -rf ~/.vim_runtime/sources_forked/vim-peepopen
fi
if [ -d ~/.vim_runtime/sources_non_forked/vim-peepopen ]; then
    rm -rf ~/.vim_runtime/sources_non_forked/vim-peepopen
fi

if [ ! -d ~/.vim_runtime/sources_forked/ctrlp.vim ]; then
    mv ~/.vim_runtime/sources_non_forked/ctrlp.vim ~/.vim_runtime/sources_forked/
fi

if [ ! -d ~/.vim_runtime/sources_forked/vim-template ]; then
    git clone --depth=1 git://github.com/aperezdc/vim-template.git ~/.vim_runtime/sources_forked/vim-template
    # change the formatting of the template
    pushdd ~/.vim_runtime/sources_forked/vim-template/templates
    sed -i "s?%YEAR%?%DATE%?g;s?%MAIL%?${user_mail}?g;s?%USER%?${user_name}?g" *
    popdd
fi

cp ./configs/bash_alias ~/.bash_alias
cp ./configs/bash_func ~/.bash_func; sed -i "s?#GITNAME#?${git_name}?g;s?#GITPASSWD#?${git_passwd}?g" ~/.bash_func
cp ./configs/bashrc ~/.bashrc
cp ./configs/tmux.conf ~/.tmux.conf
cp ./configs/my_configs.vim ~/.vim_runtime/
cp ./configs/gitconfig ~/.gitconfig; sed -i "s?#NAME#?${git_name}?g;s?#MAIL#?${git_email}?g" ~/.gitconfig
cp ./configs/git-completion.bash ~/.git-completion.bash

if [ "$(uname)" == "Darwin" ]; then
    # reconfig the tmux
    sed -i "s@#MAC @@" ~/.tmux.conf
    # cp bash_profile
    cp ./configs/bash_profile ~/.bash_profile
    # cp termianl theme
    cp ./configs/macTerminalTheme/com.apple.Terminal.plist ~/Library/Preferences/com.apple.Terminal.plist
    # change the jsoncpp include dir to make the same as in Linux
    if [ -d /usr/local/include/json ]; then
        rm -r /usr/local/include/json
        mkdir /usr/local/include/jsoncpp
        pushdd /usr/local/include/jsoncpp
        ln -s ../../Cellar/jsoncpp/*/include/json/ .
        popdd
    fi
    echo "${orange}[Tips]${endcolor} If terminal theme dose not change, use ./configs/macTerminalTheme/Xcode_style.terminal to manually change!"
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # linux copy function is different than mac
    sed -i "s@pbcopy@xsel -bi@g" ~/.vim_runtime/my_configs.vim
fi

echo "${orange}done${endcolor}"
