CREATE DATABASE miniprojet DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;
USE miniprojet;
CREATE USER 'miniprojet'@'localhost' IDENTIFIED BY 'miniprojet';
GRANT ALL PRIVILEGES ON miniprojet.* TO 'miniprojet'@'localhost' WITH GRANT OPTION;
source itineraires.sql;
