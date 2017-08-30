#! /bin/bash
#
# install_web_services.sh
# Copyright (C) 2017-08-30 Hanxiao <hah114@ucsd.edu>
#
# Distributed under terms of the MIT license.
#


sudo apt-get install mysql-server
sudo apt-get install apache2

# use php
# apt-get install php5 libapache2-mod-php5 
# apt-get install php5-mysql php5-curl php5-gd php5-idn php-pear php5-imagick php5-imap php5-mcrypt php5-memcache php5-ming php5-ps php5-pspell php5-recode php5-snmp php5-sqlite php5-tidy php5-xmlrpc php5-xsl

echo "use below command to start service..."
echo "service apache2 restart"
