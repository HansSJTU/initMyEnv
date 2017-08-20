#! /bin/bash
#
# install_shadowsocks.sh
# Copyright (C) 2017-08-20 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

. ~/.bash_alias
function install_pip
{
    wget https://bootstrap.pypa.io/get-pip.py
    python get-pip.py
    pip -V
}

command -v pip >/dev/null 2>&1 || { echo "install pip first"; install_pip; } 
sudo pip install git+https://github.com/shadowsocks/shadowsocks.git@master
read -p "Please set password for the shadowsocks: " password
read -p "Please set the port count for the shadowsocks: " port_count

config_path="/etc/shadowsocks.json"
sudo cp ../configs/shadowsocks.json ${config_path}

sudo sed -i "5a \\\t\t\"9000\":${password}" ${config_path}
for ((i=9001; i < $((9000 + ${port_count})); i++)); do
    sudo sed -i "5a \\\t\t\"${i}\":${password}," ${config_path}
done

sudo ssserver -c ${config_path} -d start

echo -e "\n${orange}========= Finished =========${endcolor}"
method=`grep "method" ${config_path} | awk -F ':' '{print $2}' | awk -F ',' '{print $1}'`
echo "You Password: ${green}\"${password}\"${endcolor}"
echo "You Encryption Methods: ${green}${method}${endcolor}"
echo "You Avaliable Port(s): "
for ((i=9000; i < $((9000 + ${port_count})); i++)); do
    echo -e "\t${green}\"${i}\"${endcolor}"
done


