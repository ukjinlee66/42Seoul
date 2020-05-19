CREATE DATABASE wordpressdb;

GRANT ALL PRIVILEGES ON word_db.* TO 'root'@'localhost';

FLUSH PRIVILEGES;

update mysql.user set plugin='mysql_native_password' where user='root';
