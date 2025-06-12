#!/bin/bash
set -e

# Initialize MariaDB if not already done
if [ ! -d "/var/lib/mysql/${SQL_DATABASE}" ]; then
    echo "Initializing database..."
    mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

    # Start MariaDB in background (just for setup)
    mysqld_safe --skip-networking &
    sleep 5

    echo "Creating database and user..."
    mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
    mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
    mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';"
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
    mysql -e "FLUSH PRIVILEGES;"

    echo "Shutting down temporary MariaDB..."
    mysqladmin -u root -p"${SQL_ROOT_PASSWORD}" shutdown
    sleep 5
fi

echo "Starting MariaDB..."
# Run MariaDB in the foreground
exec mysqld_safe
