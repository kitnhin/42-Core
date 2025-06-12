#!/bin/bash

#start mysql
service mysql start

#create database
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"

#create user and give perms
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"

#change root user
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"

#apply changes
mysql -e "FLUSH PRIVILEGES;"

#restart MySQL
mysqladmin -u root -p${SQL_ROOT_PASSWORD} shutdown

#print msg
echo "mariadb is running"

#start MySQL in foreground
exec mysqld_safe