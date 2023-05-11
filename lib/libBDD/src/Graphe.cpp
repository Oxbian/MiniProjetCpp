#include "Graphe.hpp"

/**
 * @brief Constructeur de la classe Graphe
 * @param carte carte de la ville
 */
Graphe::Graphe(Carte &carte)
{
	this->carte = carte;
	
}

/**
 * @brief Retourne une liste des waypoints voisins
 * @param waypoint_id indice du waypoint ciblé
 * @return tableau des waypoints voisins
 */
std::vector<int> Graphe::voisins(int waypoint_id)
{
	std::vector<int> voisins;
	for (auto &route: this->carte.getRoutes()) {
		if (route.getIDeb() == waypoint_id) {
			voisins.push_back(route.getIFin());
		}
		else if (route.getIFin() == waypoint_id) {
			voisins.push_back(route.getIDeb());
		}
	}
	return voisins;
}

/**
 * @brief Calcul la distance entre 2 waypoints
 * @param waypoint_1 indice du waypoint de départ
 * @param waypoint_2 indice du waypoint d'arrivée
 * @return distance en km
 */
float Graphe::distance(int waypoint_1, int waypoint_2)
{
	for (auto &route: this->carte.getRoutes()) {
        if ((route.getIDeb() == waypoint_1 && route.getIFin() == waypoint_2) ||
            (route.getIDeb() == waypoint_2 && route.getIFin() == waypoint_1)) {
            return route.getDistance();
        }
    }
    return -1;
}

/**
 * @brief Calcul du plus court chemin
 * @param waypoint_1 indice du waypoint de départ
 * @param waypoint_2 indice du waypoint d'arrivée
 * @return tableau des routes à suivre
 */
std::vector<Route> Graphe::plus_court_chemin(int waypoint_1, int waypoint_2)
{
	/*std::vector<Route> chemin;
	std::vector<int> voisins;
	std::vector<int> deja_vu;

	// Récupération du premier waypoint
	voisins = this->voisins(waypoint_1);

	while (end != waypoint_2) {

	}*/
}