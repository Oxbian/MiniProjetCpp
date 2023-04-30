#ifndef BDD_HPP
#define BDD_HPP

/* Importation des headers nécessaires */
#include <string>
#include <vector>
#include <iostream>
#include <clocale>

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class Bdd
{

private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

public:
	Bdd();
	~Bdd();

};

#endif // BDD_HPP