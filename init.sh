#! /bin/bash
#
# init.sh
# Copyright (C) 2017-07-27 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

log_dir="./Logs/"

if [ ! -d ${log_dir} ]; then
    mkdir -p ${log_dir}
fi

log_dir_abs=`realpath ${log_dir}`
current_time=`date +%Y%m%d`_`date +%T`
log_name="initLog_${current_time}"

pushd ./other_install > /dev/null
rm -rf ${log_dir_abs}/{info,err}
ln -s ${log_dir_abs}/${log_name}.err ${log_dir_abs}/err
ln -s ${log_dir_abs}/${log_name}.info ${log_dir_abs}/info
./init_mac_or_linux.sh $@ 2> >(tee "${log_dir_abs}/${log_name}.err") 1> >(tee "${log_dir_abs}/${log_name}.info")
popd > /dev/null
