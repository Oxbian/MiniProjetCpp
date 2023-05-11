#ifndef GRAPHE_HPP
#define GRAPHE_HPP

/* Importation des headers nécessaires */
#include <vector>
#include <cmath>

#include "Carte.hpp"
#include "Route.hpp"

/* Classe Graphe */
class Graphe
{
private:
	Carte carte;
    
public:
	Graphe(Carte &carte){};
	~Graphe(){};

public:
	std::vector<int> voisins(int waypoint_id);
	float distance(int waypoint_1, int waypoint_2);
	std::vector<Route> plus_court_chemin(int waypoint_1, int waypoint_2);

};

#endif // GRAPHE_HPP