#!/bin/bash
sleep 10
if [ ! -e /var/www/wordpress/wp-config.php ]; then
    wp config create	--allow-root \
    --dbname=$SQL_DATABASE \
    --dbuser=$SQL_USER \
    --dbpass=$SQL_PASSWORD \
    --dbhost=mariadb:3306 --path='/var/www/wordpress'
fi

wp core install \
    --allow-root \
    --url="$SITE_URL" \
    --title="$SITE_TITLE" \
    --admin_user="$ADMIN_NAME" \
    --admin_password="$ADMIN_PASSWORD" \
    --admin_email="$ADMIN_EMAIL" \
    --path='/var/www/wordpress'

echo "admin created!"

wp user create $USER_NAME $USER_EMAIL \
    --role=author \
    --user_pass=$USER_PASSWORD \
    --allow-root \
    --path='/var/www/wordpress'


mkdir -p ./run/php
echo "normal user created!"

echo "wordpress is now running"

/usr/sbin/php-fpm7.3 -F