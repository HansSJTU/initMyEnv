#!/bin/bash
version="v1.0"

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
source "${base_dir}/configs/bash_func"

# Define OS specific downloads
if [ "$(uname)" == "Darwin" ]; then
    echo "${green}[Operation System Detect]${endcolor} Mac OSX "
    plugin_file="${base_dir}/configs/install.mac"
    os_name="OSX"
    command -v brew >/dev/null 2>&1 || { ${base_dir}/other_install/install_brew.sh; }
    sudo easy_install pip
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "${green}[Operation System Detect]${endcolor} Linux "
    plugin_file="${base_dir}/configs/install.linux"
    os_name="Linux"
    echo "${orange}Start to Update apt-get...${endcolor}"
    sudo apt-get update
    echo "${orange}Start to Setup Color Theme...${endcolor}"
    pushd set_linux_theme/themes > /dev/null
    ./Xcode
    popd > /dev/null
else
    echo "${red}[Error]${endcolor} Unkown Operation System!" 1>&2
    echo "This init script only support Mac OSX and Linux!" 1>&2
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
backup_and_copy ~/.inputrc
backup_and_copy ~/Library/Preferences/com.apple.Terminal.plist #terminal theme binary config

${base_dir}/other_install/install_vim.sh ${user_mail} ${user_name}

cp ${base_dir}/configs/bash_alias ~/.bash_alias
cp ${base_dir}/configs/bash_func ~/.bash_func; sed -i "s?#GITNAME#?${git_name}?g;s?#GITPASSWD#?${git_passwd}?g" ~/.bash_func
cp ${base_dir}/configs/bashrc ~/.bashrc
cp ${base_dir}/configs/inputrc ~/.inputrc
cp ${base_dir}/configs/tmux.conf ~/.tmux.conf
cp ${base_dir}/configs/my_configs.vim ~/.vim_runtime/
cp ${base_dir}/configs/gitconfig ~/.gitconfig; sed -i "s?#NAME#?${git_name}?g;s?#MAIL#?${git_email}?g" ~/.gitconfig
cp ${base_dir}/configs/git-completion.bash ~/.git-completion.bash

# set go path
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

# config the tmux with different version
tmux_version=$(tmux -V | awk '{print $2}')
if [[ $(echo "${tmux_version} >= 2.3" | bc) -eq 1 ]]; then
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
    sed -i "s@pbcopy@xsel -bi@g" ~/.vim_runtime/my_configs.vim
    sed -i "s@pbcopy@xsel -bi@g" ~/.bash_func
fi

echo "${orange}done${endcolor}"
