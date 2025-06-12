FROM debian:bookworm

#install mdb
RUN apt update && apt upgrade -y
RUN apt-get install mariadb-server -y

#copy conf
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#copy script into container
COPY ./tools/mdbscript.sh ./mdbscript.sh
RUN chmod 755 mdbscript.sh

EXPOSE 3306

#run script
CMD ["./mdbscript.sh"]


