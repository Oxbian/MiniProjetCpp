#ifndef GRAPHE_HPP
#define GRAPHE_HPP

/* Importation des headers nécessaires */
#include <vector>
#include <cmath>
#include <algorithm>

#include "Carte.hpp"
#include "Route.hpp"

/* Classe Graphe */
class Graphe
{
private:
	Carte carte;
    
public:
	Graphe(Carte &carte);
	Graphe(){};
	~Graphe(){};

public:
	std::vector<int> voisins(int waypoint_id);
	float distance(int waypoint_1, int waypoint_2);
	std::vector<Route> plus_court_chemin(int waypoint_1, int waypoint_2);
	Route getRoute(int waypoint_1, int waypoint_2);
	void checkVoisins(std::vector<int> &voisins, std::vector<int> &deja_vu, std::vector<int> &wrong_way);
	int minVoisin(std::vector<int> &voisins, int waypoint);
	int distTot(std::vector<Route> chemin);
	int getWaypointID(std::string nom);
};

#endif // GRAPHE_HPP