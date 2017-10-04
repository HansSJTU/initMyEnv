#! /bin/bash
#
# install_htop_without_root.sh
# Copyright (C) 2017 Hanxiao He <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#


pushd ${HOME} > /dev/null
wget http://hisham.hm/htop/releases/1.0.3/htop-1.0.3.tar.gz
tar zxf htop-1.0.3.tar.gz
pushd htop-1.0.3 > /dev/null
./configure; make;

if [ ! -d "${HOME}/local/bin" ]; then
    mkdir -p "${HOME}/local/bin"
fi

mv htop ${HOME}/local/bin/
popd > /dev/null
popd > /dev/null
rm -rf ${HOME}/htop-1.0.3.tar.gz ${HOME}/htop-1.0.3
