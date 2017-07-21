#! /bin/bash
#
# change.sh
# Copyright (C) 2017-07-20 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

command -v duti >/dev/null 2>&1 || { HOMEBREW_NO_AUTO_UPDATE=1 brew install duti; }

all_list=(avi wmv mpeg mp4 mov mkv flv f4v m4v rmvb rm 3gp dat ts mts vob)
for one in ${all_list[@]}; do
    duti -s io.mpv ".${one}" all
    open_way=`duti -x ${one} | sed -n "3p"`
    echo "${one}: ${open_way}"
done
