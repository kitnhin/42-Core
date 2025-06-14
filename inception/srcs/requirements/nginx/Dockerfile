FROM debian:buster

#install nginx
RUN apt update && apt upgrade -y
RUN apt install nginx -y

#copy script into container
COPY ./tools/nginxscript.sh ./nginxscript.sh
RUN chmod 755 nginxscript.sh

#install vim and curl
RUN apt install vim -y
RUN apt install curl -y

#install SSL
RUN mkdir -p /etc/nginx/ssl
RUN apt install openssl -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=MS/ST=KL/L=KL/O=42/OU=42/CN=cheelim.42.fr/UID=cheelim"

#create and copy config file
RUN mkdir -p /var/run/nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

#expose port
EXPOSE 443

#stupid one can only have one CMD so everything wanna do when running need put inside the script
CMD ["./nginxscript.sh"]