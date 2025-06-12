FROM debian:bookworm

#install wget
RUN apt update && apt upgrade -y
RUN apt-get -y install wget

#install php
RUN apt-get install -y php7.3 \
php-fpm \
php-mysql \
mariadb-client

#install wordpress using wget
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

#unzip the wordpress .tar file and remove the tar file
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && \
rm wordpress-6.0-fr_FR.tar.gz

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

#run script
CMD ["./autoconfig.sh"]
					
