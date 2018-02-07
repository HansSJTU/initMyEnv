#! /bin/bash
#
# install_tensorflow_1.0.sh
# Copyright (C) 2017-11-23 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

command -v pip >/dev/null 2>&1 || { ./install_pip.sh; }

if [ "$(uname)" == "Darwin" ]; then
    sudo pip install --upgrade tensorflow-gpu https://pypi.python.org/packages/0d/d7/b49a6ceb055f392f91bce25eb6e1665f9b2f0a4628f7acdbccf1cd1d0ee6/tensorflow-1.0.0-cp27-cp27m-macosx_10_11_x86_64.whl#md5=51235fbe34e705bcdb1b5bbd6a482c57
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    sudo pip install --upgrade tensorflow-gpu https://pypi.python.org/packages/7b/c5/a97ed48fcc878e36bb05a3ea700c077360853c0994473a8f6b0ab4c2ddd2/tensorflow-1.0.0-cp27-cp27mu-manylinux1_x86_64.whl#md5=a7483a4da4d70cc628e9e207238f77c0
fi

