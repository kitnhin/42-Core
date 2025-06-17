#!/bin/bash

# used to test restart lol
# exit(1)

#chatgpt teach one, for safety in case one of the commands fail it exits
set -e

#ensure the mysqld socket dir exists (somehow tested again and didnt need this anymore wts but wtv la i lazy delete ltr got error)
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld #say mysql owns this dir so it has full perms to do wtv it wants

#install / setup the database structure, including tables, log files, folders, etc
echo "setting up mysql"
mysql_install_db --user=mysql --datadir=/var/lib/mysql #this function already checks if a database structure exist and auto avoids reinstalling over overwriting

#set configs into a file
echo "doing configs using bootstrap"

echo "
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES; " > /tmp/init.sql

#use bootstrap to run msql and do the configs
mysqld --user=mysql --bootstrap < /tmp/init.sql

#clean up temp file
rm /tmp/init.sql

echo "running mysql fr now"

# starts mysqld fr now
exec mysqld_safe --user=mysql
