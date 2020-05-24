FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server
RUN apt-get install -y php-fpm php php-cli
RUN apt-get install -y php-mbstring
RUN apt-get install -y php-mysql
RUN apt-get install -y zip
RUN apt-get install -y openssl

RUN rm -fr /etc/nginx/sites-available/default;
RUN rm -fr /etc/nginx/sites-enabled/default;
COPY ./srcs/init_db.sql /var/
COPY ./srcs/wordpressdb.sql /var/
COPY ./srcs/phpindex.php /var/www/html/index.php
COPY ./srcs/wordpress.zip /var/www/html/
COPY ./srcs/phpmyadmin.zip /var/www/html/
COPY ./srcs/localhost /etc/nginx/sites-available/default
RUN ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

RUN unzip /var/www/html/wordpress.zip -d /var/www/html
RUN unzip /var/www/html/phpmyadmin.zip -d /var/www/html
RUN mv /var/www/html/phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
RUN rm -fr /var/www/html/wordpress.zip
RUN rm -fr /var/www/html/phpmyadmin.zip

COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
RUN service mysql start && mysql -u root mysql < /var/init_db.sql && mysql wordpressdb -u root --password= < /var/wordpressdb.sql

COPY ./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=KR/ST=42/L=Seoul/O=42/CN=youlee' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 755 /var/www/*

RUN service nginx start
RUN service php7.3-fpm start

EXPOSE 80 443 8080 6060
