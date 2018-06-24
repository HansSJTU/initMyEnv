#! /bin/bash
#
# install_tensorflow.sh
# Copyright (C) 2017-11-23 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

echo -e "\n******* [INFO] *******\nThis script is to install different versions of tensorflow: \n"
sleep 1

read -rp "Version to Install (1.0.0, 1.2.3, 1.5.0): " version
if [[ $(echo "${version}" | grep -c "[1].[0-9].[0-9]") -eq 0 ]]; then
    echo "[ERROR] Version number error"
    exit -1
fi

read -rp "Python Version (2.7, 3.4, 3.5, 3.6): " python_version
if [[ $(echo "${python_version}" | grep -c "[23].[4567]") -eq 0 ]]; then
    echo "[ERROR] Python version number error"
    exit -1
fi

read -rp "GPU Enable (1 for GPU, 0 for CPU): " GPU_enable
if [[ $(echo "${GPU_enable}" | grep -c "[01]") -eq 0 ]]; then
    echo "[ERROR] GPU Enable number error"
    exit -1
fi

function validate_url
{
    if [[ $(wget -S --spider "$1" 2>&1 | grep 'HTTP/1.1 200 OK') ]]; then
        echo "true"
    else
        echo "false"
    fi
}

py_version_1=${python_version:0:1}
py_version_2=${python_version:2:3}
if [ "$(uname)" == "Darwin" ]; then
    if [[ ${GPU_enable} -eq 1 ]]; then
        echo "[ERROR] Mac does not support gpu version, exiting..." 1>&2
        exit -1
    fi
    url="https://storage.googleapis.com/tensorflow/mac/cpu/tensorflow-${version}-py${py_version_1}-none-any.whl"
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    if [[ ${GPU_enable} -eq 1 ]]; then
        proc="gpu"
        suffix="_gpu"
    else
        proc="cpu"
        suffix=""
    fi
    if [[ ${py_version_1} -eq 2 ]]; then
        url="https://storage.googleapis.com/tensorflow/linux/${proc}/tensorflow${suffix}-${version}-cp${py_version_1}${py_version_2}-none-linux_x86_64.whl"
    else
        url="https://storage.googleapis.com/tensorflow/linux/${proc}/tensorflow${suffix}-${version}-cp${py_version_1}${py_version_2}-cp${py_version_1}${py_version_2}m-linux_x86_64.whl"
    fi
fi

if [[ $(validate_url "${url}") == 'false' ]]; then
    echo "[ERROR] File dose not exists: ${url}"
    exit -1
fi

if [[ ${py_version_1} -eq 2 ]]; then
    command -v pip >/dev/null 2>&1 || { ./install_pip.sh; }
    sudo pip install --upgrade ${url}
else
    sudo pip3 install --upgrade ${url}
fi
