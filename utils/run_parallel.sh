#!/bin/bash


work_dir=$(pwd)
echo $work_dir


parallel --gnu \
        --workdir $work_dir \
        --joblog ./my_parallel.log \
        --tag \
        --linebuffer \
        --results ./my_results/ \
        --progress \
        --jobs 24 \
        --sshloginfile ip.list \
        bash $work_dir/run.sh {} \
        :::: ./todo.list