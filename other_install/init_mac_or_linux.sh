#! /bin/bash
#
# init_mac_or_linux.sh
# Copyright (C) 2017 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

base_dir=$(dirname $(pwd))

echo -ne "\n"

shopt -s expand_aliases
source "${base_dir}/configs/bash_alias"
source "${base_dir}/configs/bash_func"

# Define OS specific downloads
if [ "$(uname)" == "Darwin" ]; then
  echo "${green}[Operation System Detect]${endcolor} Mac OSX "
  plugin_file="${base_dir}/configs/install.mac"
  os_name="OSX"
  command -v brew > /dev/null 2>&1 || { ${base_dir}/other_install/install_brew.sh; }
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  echo "${green}[Operation System Detect]${endcolor} Linux "
  plugin_file="${base_dir}/configs/install.linux"
  os_name="Linux"

  # Package Controller Update
  if command -v apt-get > /dev/null 2>&1; then
    echo "${orange}Start to Update apt-get...${endcolor}"
    sudo apt-get update
  elif command -v yum > /dev/null 2>&1; then
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

if ! [ -x "$(command -v go)" ]; then
  ./install_golang.sh --64
fi

if ! [ -x "$(command -v clang-format-7)" ]; then
  ./install_clang_format_7.sh
fi

if ! [ -x "$(command -v shfmt)" ]; then
  go get -u mvdan.cc/sh/cmd/shfmt
fi

function install_plugins() {
  if [ $1 == "OSX" ]; then
    brew install "$2"
  elif [ $1 == "Linux" ]; then
    if command -v apt-get > /dev/null 2>&1; then
      sudo apt-get install "$2" -y
    elif command -v yum > /dev/null 2>&1; then
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
total_plugin_num=$(cat ${plugin_file} | wc -l)
current_plugin_num=1
for plugin in $(cat ${plugin_file}); do
  echo "${green}[${current_plugin_num} / ${total_plugin_num}] ${endcolor} : ${plugin}..."
  ((current_plugin_num++))
  install_plugins ${os_name} ${plugin}
done

echo "${green}[FINISHED]${endcolor} done installing! "

if [ ! -d ~/.setting_backup ]; then
  mkdir ~/.setting_backup
fi

sudo apt install vim-gtk
sudo bash install_pip.sh
. ${base_dir}/other_install/install_vim.sh

function backup_and_copy() {
  if [ -f "$1" ]; then
    backup ~/.$1
    mv ${backup_file_dir} ~/.setting_backup/
    ln -f ${base_dir}/configs/$1 ~
  fi
}

BackupCopyFileList=("bash_alias" "bash_func" "bashrc" "tmux.conf"
  "vimrc" "gitconfig" "bash_profile" "inputrc" "git-completion.bash")
for file in ${BackupCopyFileList[*]}; do
  backup_and_copy ${file}
done

if [ -f "~/.vim_runtime/my_configs.vim" ];then
  backup "~/.vim_runtime/my_configs.vim"
  mv ${backup_file_dir} ~/.setting_backup/
fi
ln -f ${base_dir}/configs/my_configs.vim ~/.vim_runtime/

# config for sed
if [ "$(uname)" == "Darwin" ]; then
  source "${base_dir}/configs/bashrc"
  type sed 1>&2
fi
