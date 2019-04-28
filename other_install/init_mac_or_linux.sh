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
    user_name="Xuyang Tao"
    user_mail="taoxuy@google.com"
    git_name="taoxuy"
    git_email="taoxuy@google.om"
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

    # Package Controller Update
    if command -v apt-get >/dev/null 2>&1; then
        echo "${orange}Start to Update apt-get...${endcolor}"
        sudo apt-get update
    elif command -v yum >/dev/null 2>&1; then
        echo "${orange}Start to Update yum...${endcolor}"
        sudo yum update -y
    fi

    # Set terminal theme
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
        if command -v apt-get >/dev/null 2>&1; then
            sudo apt-get install "$2" -y
        elif command -v yum >/dev/null 2>&1; then
            sudo yum install -y "$2"
        else
            echo "[Install Error] Package Installer Not Detected For: $2"
        fi
        wait
    else
        echo "[Install Error] Package Installer Not Detected For: $2"
    fi
}

echo "${orange}Start to Install Plugins...${endcolor}"
total_plugin_num=`cat ${plugin_file} | wc -l`
current_plugin_num=1
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
backup_and_copy ~/.bash_func
backup_and_copy ~/.bashrc
backup_and_copy ~/.tmux.conf
backup_and_copy ~/.vim_runtime/my_configs.vim
backup_and_copy ~/.vimrc
backup_and_copy ~/.gitconfig
backup_and_copy ~/.bash_profile
backup_and_copy ~/.inputrc
backup_and_copy ~/Library/Preferences/com.apple.Terminal.plist #terminal theme binary config

${base_dir}/other_install/install_vim.sh ${user_name} ${user_mail}

# config for sed
if [ "$(uname)" == "Darwin" ]; then
    source "${base_dir}/configs/bashrc"
    type sed 1>&2
fi

ln -f  ${base_dir}/configs/bash_alias ~/.bash_alias
ln -f  ${base_dir}/configs/bash_func ~/.bash_func; sed -i "s?#GITNAME#?${git_name}?g;s?#GITPASSWD#?${git_passwd}?g" ~/.bash_func
ln -f  ${base_dir}/configs/bashrc ~/.bashrc
ln -f  ${base_dir}/configs/inputrc ~/.inputrc
ln -f  ${base_dir}/configs/tmux.conf ~/.tmux.conf
ln -f  ${base_dir}/configs/my_configs.vim ~/.vim_runtime/
ln -f  ${base_dir}/configs/gitconfig ~/.gitconfig; sed -i "s?#NAME#?${git_name}?g;s?#MAIL#?${git_email}?g" ~/.gitconfig
ln -f  ${base_dir}/configs/git-completion.bash ~/.git-completion.bash
ln -f  ${base_dir}/configs/bash_profile ~/.bash_profile
if [ ! -e ~/.web_list ]; then
    ln -f  ${base_dir}/configs/web_list ~/.web_list
fi

# config the tmux with different version
tmux_version=$(tmux -V | awk '{print $2}')
if [ $(echo "2.3 ${tmux_version}" | awk '{if($1>$2) {print 0} else {print 1}}') -eq 1 ]; then
    sed -i "s@#HV2.3 @@" ~/.tmux.conf
else
    sed -i "s@#LV2.3 @@" ~/.tmux.conf
fi
if ! [ -x "$(command -v go)" ]; then
  ./install_go.sh --64
fi

if [ ! -f "${HOME}/.vim_runtinme/source_forked/YouCompleteMe" ]; then
  git clone https://github.com/Valloric/YouCompleteMe.git ~/.vim_runtime/sources_forked/YouCompleteMe
  pushd ~/.vim_runtime/sources_forked/YouCompleteMe
  git submodule update --init --recursive
  python install.py --go-completer --clang-completer
  popd
fi

./install_go.sh --64
pushd ~/.vim_runtime/sources_forked/YouCompleteMe
git submodule update --init --recursive
python install.py --go-completer --clang-completer
popd

git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
echo "${orange}done${endcolor}"

sudo apt-get install clang-formatter
pip install --user yapf
