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
#include <cppconn/exception.h>

#include "Contour.hpp"
#include "Point.hpp"
#include "Route.hpp"
#include "Waypoint.hpp"
#include "Ville.hpp"
#include "Carte.hpp"

/* Classe Bdd */
class Bdd
{

private:
	sql::Driver *driver;
	sql::Connection *conn;

public:
	Bdd();
	Bdd(std::string host, std::string database, std::string user, std::string password);
	~Bdd();

	Contour creerContour();
	std::vector<Waypoint *> creerWaypoints();
	void creerVilles(std::vector<Waypoint *> waypoints);
	std::vector<Route> creerRoute(std::vector<Waypoint *> waypoints);
	Carte creerCarte();
	int getId(std::string nom, std::vector<Waypoint *> waypoints);
};

#endif // BDD_HPP