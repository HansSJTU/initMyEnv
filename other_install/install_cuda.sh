#! /bin/bash
#
# install_cuda.sh
# Copyright (C) 2017-11-22 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

echo -e "\n****** [INFO] *******\nThis script is to install CUDA 8.0 with CUBLAS 8.0 and CUDNN 6.0"
echo "The CUDA version dose not support Tensorflow 1.5!"
sleep 3
echo "Downloading will start in 5 seconds"
sleep 5

if [[ ! -d ~/cuda_install ]]; then
    mkdir -p ~/cuda_install
fi

pushd ~/cuda_install > /dev/null
wget "http://108.61.247.112/public/cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64.deb"
wget "http://108.61.247.112/public/cuda-repo-ubuntu1404-8-0-local-cublas-performance-update_8.0.61-1_amd64.deb"
wget "http://108.61.247.112/public/libcudnn6_6.0.21-1+cuda8.0_amd64.deb"

sudo dpkg -i "cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64.deb"
sudo apt-get update
sudo apt-get install cuda -y
sudo dpkg -i "cuda-repo-ubuntu1404-8-0-local-cublas-performance-update_8.0.61-1_amd64.deb"
sudo dpkg -i "libcudnn6_6.0.21-1+cuda8.0_amd64.deb"
sudo apt-get install libcupti-dev -y
sudo apt-get install linux-headers-$(uname -r) -y
popd > /dev/null

echo "export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64/:/usr/local/cuda/lib64:\$LD_LIBRARY_PATH" >> ~/.bashrc
echo "export PATH=/usr/local/cuda-8.0/bin:/usr/local/cuda/bin:\$PATH" >> ~/.bashrc
