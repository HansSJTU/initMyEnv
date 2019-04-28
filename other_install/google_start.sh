#! /bin/bash
#
# start.sh
# Copyright (C) 2018-06-22 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#

xmodmap -e "clear Lock"
xmodmap -e "keycode 66 = Escape NoSymbol Escape"
xmodmap -v ~/.modmap.file > /dev/null
prodaccess
