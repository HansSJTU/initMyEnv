#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019-01-08 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.

from tabulate import tabulate

contents = []

with open('./ss_ports', 'r') as f:
    for line in f.readlines():
        contents.append(line.strip().split('|'))

with open('./ss_ports_table', 'w') as f:
    f.write(tabulate(contents[1:], contents[0], tablefmt="grid"))
