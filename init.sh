#! /bin/bash
#
# init.sh
# Copyright (C) 2017-07-27 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#
work_dir=$(pwd)
log_dir="${work_dir}/Logs/"

if [ ! -d "${log_dir}" ]; then
    mkdir -p "${log_dir}"
fi

current_time="$(date +%Y%m%d)_$(date +%T)"
log_name="initLog_${current_time}"

pushd ./other_install > /dev/null
rm -rf "${log_dir}"/{info,err}
ln -s "${log_dir}/${log_name}.err" "${log_dir}/err"
ln -s "${log_dir}/${log_name}.info" "${log_dir}/info"
./init_mac_or_linux.sh "$@" 2> >(tee "${log_dir}/${log_name}.err") 1> >(tee "${log_dir}/${log_name}.info")
popd > /dev/null
