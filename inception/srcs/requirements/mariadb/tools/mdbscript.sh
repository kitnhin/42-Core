#!/bin/bash
set -e

# Ensure the mysqld socket dir exists
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# Initialize MariaDB data directory if not done
echo "setting up mysql"
mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Use bootstrap mode to set up database and users
echo "doing configs using bootstrap"
cat <<EOF > /tmp/init.sql
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

# Bootstrap loads DB and runs SQL without hanging
mysqld --user=mysql --bootstrap < /tmp/init.sql

# Clean up temp file
rm /tmp/init.sql

echo "running mysql fr now"

# Start MariaDB server (normal mode) in foreground
exec mysqld_safe --user=mysql
