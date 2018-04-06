#! /bin/bash
#
# install_cuda.sh
# Copyright (C) 2017-11-22 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

echo -e "\n******* [INFO] *******\nThis script is to install: \n \
    \t(1) CUDA 8.0 with CUBLAS Patch and CUDNN 6.0 (for tensorflow 1.0) on Ubuntu 14.04 \n \
    \t(2) CUDA 9.0 with CUBLAS 9.0 and CUDNN 7.0 (for tensorflow 1.5) on Ubuntu 16.04 \n \
    \t(3) CUDA 9.1 with CUBLAS 9.0 and CUDNN 7.1.2\n"
sleep 1
read -rp "Version To Install (1/2/3): " version

if [[ ${version} -eq 1 ]]; then
    cuda_addr="https://developer.nvidia.com/compute/cuda/8.0/Prod2/local_installers/cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64-deb"
    cublas_addr="http://108.61.247.112/public/cuda-repo-ubuntu1404-8-0-local-cublas-performance-update_8.0.61-1_amd64.deb"
    cudnn_addr="http://108.61.247.112/public/libcudnn6_6.0.21-1+cuda8.0_amd64.deb"
    suffix="8.0"
elif [[ ${version} -eq 2 ]]; then
    cuda_addr="https://developer.nvidia.com/compute/cuda/9.0/Prod/local_installers/cuda-repo-ubuntu1604-9-0-local_9.0.176-1_amd64-deb"
    cublas_addr="http://108.61.247.112/public/cuda-repo-ubuntu1604-9-0-local-cublas-performance-update_1.0-1_amd64.deb"
    cudnn_addr="http://108.61.247.112/public/libcudnn7_7.0.5.15-1+cuda9.0_amd64.deb"
    suffix="9.0"
elif [[ ${version} -eq 3 ]]; then
    cuda_addr="https://developer.nvidia.com/compute/cuda/9.1/Prod/local_installers/cuda-repo-ubuntu1604-9-1-local_9.1.85-1_amd64"
    cublas_addr="https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/3/cuda-repo-ubuntu1604-9-1-local-cublas-performance-update-3_1.0-1_amd64"
    cudnn_addr="108.61.247.112/public/libcudnn7_7.1.2.21-1+cuda9.1_amd64.deb"
    suffix="9.1"
else
    echo "[ERROR] Version Entered Error, exiting..." 1>&2
    exit -1
fi

if [[ ! -d ~/cuda_install ]]; then
    mkdir -p ~/cuda_install
fi

# download all files
pushd ~/cuda_install > /dev/null
wget -O cuda_${suffix}.deb "${cuda_addr}"
wget -O cublas_${suffix}.deb "${cublas_addr}"
wget -O cudnn_${suffix}.deb "${cudnn_addr}"

# install CUDA
sudo dpkg -i cuda_${suffix}.deb
sudo apt-get update
sudo apt-get install cuda

# install cuBLAS and cuDNN
sudo dpkg -i cublas_${suffix}.deb
sudo dpkg -i cudnn_${suffix}.deb
sudo apt-get install libcupti-dev
sudo apt-get install "linux-headers-$(uname -r)"
popd > /dev/null

bashrc_inject_1="export LD_LIBRARY_PATH=/usr/local/cuda-${suffix}/lib64/:/usr/local/cuda/lib64:\$LD_LIBRARY_PATH"
bashrc_inject_2="export PATH=/usr/local/cuda-${suffix}/bin:/usr/local/cuda/bin:\$PATH"
if [[ $(grep -c "${bashrc_inject_1}" "${HOME}"/.bashrc) -eq 0 ]]; then
    echo "${bashrc_inject_1}" >> ~/.bashrc
fi
if [[ $(grep -c "${bashrc_inject_2}" "${HOME}"/.bashrc) -eq 0 ]]; then
    echo "${bashrc_inject_2}" >> ~/.bashrc
fi

echo "You can clean the install package if the installment is finished: ${HOME}/cuda_install"
