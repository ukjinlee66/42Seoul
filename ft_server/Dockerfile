FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server
RUN apt-get install -y php7.3
RUN apt-get install -y php7.3-fpm
RUN apt-get install -y php7.3-cli
RUN apt-get install -y php7.3-mbstring
RUN apt-get install -y php7.3-mysql

EXPOSE 80
