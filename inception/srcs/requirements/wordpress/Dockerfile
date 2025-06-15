FROM debian:buster

#install wget
RUN apt update && apt upgrade -y
RUN apt-get -y install wget

#install php
RUN apt-get install -y php7.3 \
php-fpm \
php-mysql \
mariadb-client

#install vim and curl
RUN apt install vim -y
RUN apt install curl -y

#install wordpress using wget
RUN wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0.tar.gz && rm wordpress-6.0.tar.gz

#give perms
RUN chown -R root:root /var/www/wordpress

#copy config
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

#install CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

#copy init script
COPY ./tools/autoconfig.sh ./autoconfig.sh
RUN chmod 755 autoconfig.sh

#expose port
EXPOSE 9000 3306

#run script
CMD ["./autoconfig.sh"]

