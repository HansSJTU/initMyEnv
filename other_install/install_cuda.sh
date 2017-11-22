#! /bin/bash
#
# install_cuda.sh
# Copyright (C) 2017-11-22 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

if [[ ! -d ~/cuda_install ]]; then
    mkdir -p ~/cuda_install
fi
pushd ~/cuda_install > /dev/null
wget "http://108.61.247.112/public/cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64-deb"
wget "http://108.61.247.112/public/cuda-repo-ubuntu1404-8-0-local-cublas-performance-update_8.0.61-1_amd64-deb"
wget "http://108.61.247.112/public/libcudnn6_6.0.21-1+cuda8.0_amd64.deb"
sudo dpkg -i "cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64-deb"
sudo dpkg -i "cuda-repo-ubuntu1404-8-0-local-cublas-performance-update_8.0.61-1_amd64-deb"
sudo dpkg -i "libcudnn6_6.0.21-1+cuda8.0_amd64.deb"
popd > /dev/null
