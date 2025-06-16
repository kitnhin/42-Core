FROM debian:buster

#install mdb
RUN apt update && apt upgrade -y
RUN apt-get install mariadb-server -y

#install top / ps for process viewing
RUN apt update && apt install -y procps

#copy conf
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#copy script into container
COPY ./tools/mdbscript.sh ./mdbscript.sh
RUN chmod 755 mdbscript.sh

#create socket dir
RUN mkdir -p /var/run/mysqld && chown mysql:mysql /var/run/mysqld

EXPOSE 3306

#run script
CMD ["./mdbscript.sh"]


