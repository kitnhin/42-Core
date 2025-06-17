#!/bin/bash

#sleep first to make sure mariadb is ready
sleep 10

#creates the wp-config.php to skip the first setup page (see the guide pic)
#! -e = not 
if [ ! -e /var/www/wordpress/wp-config.php ]; then
    wp config create \
    --allow-root \
    --dbname=$SQL_DATABASE \
    --dbuser=$SQL_USER \
    --dbpass=$SQL_PASSWORD \
    --dbhost=mariadb:3306 --path='/var/www/wordpress'
fi

#fill in the info for the second setup page (welcome page)
wp core install \
    --allow-root \
    --url="$SITE_URL" \
    --title="$SITE_TITLE" \
    --admin_user="$ADMIN_NAME" \
    --admin_password="$ADMIN_PASSWORD" \
    --admin_email="$ADMIN_EMAIL" \
    --path='/var/www/wordpress'

echo "welcome pages passsed and admin created!"

#create new user cuz subject ask one
wp user create $USER_NAME $USER_EMAIL \
    --role=author \
    --user_pass=$USER_PASSWORD \
    --allow-root \
    --path='/var/www/wordpress'

echo "normal user created!"

#create php dir
mkdir -p ./run/php

echo "wordpress is now running"

#runs phpfpm 
/usr/sbin/php-fpm7.4 -F