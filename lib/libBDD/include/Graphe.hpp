#ifndef GRAPHE_HPP
#define GRAPHE_HPP

/* Importation des headers nécessaires */
#include <vector>
#include <cmath>
#include <algorithm>

#include "Carte.hpp"
#include "Route.hpp"

/* Constantes */
const int INFINI = 1e7;

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
	float distance(int waypoint_1, int waypoint_2);
	std::vector<Route> plus_court_chemin(int waypoint_1, int waypoint_2);
	Route getRoute(int waypoint_1, int waypoint_2);
	int distTot(std::vector<Route> chemin);
	int getWaypointID(std::string nom);
	std::vector<std::vector<int>> createMatrice();
	std::vector<Route> Dijkstra(std::vector<std::vector<int>> &graphe, int src, int end);
	int minDist(std::vector<int> &dist, std::vector<int> &Q);
	
};

#endif // GRAPHE_HPP