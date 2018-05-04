#! /bin/bash
#
# init_mac_or_linux.sh
# Copyright (C) 2017 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

base_dir=$(dirname $(pwd))
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
source "${base_dir}/configs/bash_alias"

# Define OS specific downloads
if [ "$(uname)" == "Darwin" ]; then
    echo "${green}[Operation System Detect]${endcolor} Mac OSX "
    plugin_file="${base_dir}/configs/install.mac"
    os_name="OSX"
    unalias cp
    unalias rm
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "${green}[Operation System Detect]${endcolor} Linux "
    plugin_file="${base_dir}/configs/install.linux"
    os_name="Linux"
else
    echo "${red}[Error]${endcolor} Unkown Operation System!" 1>&2
    echo "This init script only support Mac OSX and Linux!" 1>&2
EOF
fi

${base_dir}/other_install/install_vim.sh ${user_name} ${user_mail}

cp ${base_dir}/configs/bash_alias ~/.bash_alias
cp ${base_dir}/configs/bashrc ~/.bashrc
cp ${base_dir}/configs/inputrc ~/.inputrc
cp ${base_dir}/configs/tmux.conf ~/.tmux.conf
cp ${base_dir}/configs/my_configs.vim ~/.vim_runtime/
cp ${base_dir}/configs/gitconfig ~/.gitconfig; sed -i "s?#NAME#?${git_name}?g;s?#MAIL#?${git_email}?g" ~/.gitconfig
cp ${base_dir}/configs/git-completion.bash ~/.git-completion.bash
if [ ! -e ~/.web_list ]; then
    cp ${base_dir}/configs/web_list ~/.web_list
fi

# config the tmux with different version
#/${base_dir}/other_install/install_tmux_without_root.sh
unalias tmux
tmux_version=$(command -v tmux > /dev/null 2>&1 && tmux -V | awk '{print $2}' || echo "2.5")
if [ $(echo "2.3 ${tmux_version}" | awk '{if($1>$2) {print 0} else {print 1}}') -eq 1 ]; then
    sed -i "s@#HV2.3 @@" ~/.tmux.conf
else
    sed -i "s@#LV2.3 @@" ~/.tmux.conf
fi

if [ "$(uname)" == "Darwin" ]; then
    # reconfig the tmux
    sed -i "s@#MAC @@" ~/.tmux.conf
    # cp bash_profile
    cp ${base_dir}/configs/bash_profile ~/.bash_profile
    # cp termianl theme
    cp ${base_dir}/configs/macTerminalTheme/com.apple.Terminal.plist ~/Library/Preferences/com.apple.Terminal.plist
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
    # reconfig the tmux
    sed -i "s@#LINUX @@" ~/.tmux.conf
    # linux copy function is different than mac
    sed -i "s@pbcopy@xsel@g" ~/.vim_runtime/my_configs.vim
    cp ${base_dir}/configs/bash_profile ~/.bash_profile
fi

echo "${orange}done${endcolor}"
