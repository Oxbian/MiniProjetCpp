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
	Route route = this->getRoute(waypoint_1, waypoint_2);
	if (route.getIDeb() == -1 && route.getIFin() == -1) {
    	return -1;
	}
	return route.getDistance();
}

/**
 * @brief Calcul du plus court chemin
 * @param waypoint_1 indice du waypoint de départ
 * @param waypoint_2 indice du waypoint d'arrivée
 * @return tableau des routes à suivre
 */
std::vector<Route> Graphe::plus_court_chemin(int waypoint_1, int waypoint_2)
{
	// Si les waypoints n'existent pas ou sont égaux on retourne un tableau vide
	if (waypoint_1 == -1 || waypoint_2 == -1 || waypoint_1 == waypoint_2) {
		return std::vector<Route>();
	}

	std::vector<Route> chemin;
	std::vector<int> wrong_way;
	std::vector<int> deja_vu;

	int end = waypoint_1;

	while (end != waypoint_2) {
		std::vector<int> voisins = this->voisins(end);
		this->checkVoisins(voisins, deja_vu, wrong_way);

		if (voisins.size() == 0) {
			wrong_way.push_back(end);
			end = deja_vu.back();
			deja_vu.pop_back();
			chemin.pop_back();
		} else {
			deja_vu.push_back(end);
			end = minVoisin(voisins, end);
			chemin.push_back(this->getRoute(end, deja_vu.back()));
		}
	}
	return chemin;
}

/**
 * @brief Fonction pour récupérer une route entre deux waypoints
 * @param waypoint_1 Indice du premier waypoint
 * @param waypoint_2 Indice du deuxième waypoint
 * @return L'objet route correspondant
 */
Route Graphe::getRoute(int waypoint_1, int waypoint_2)
{
	for (auto &route: this->carte.getRoutes()) {
		if ((route.getIDeb() == waypoint_1 && route.getIFin() == waypoint_2) ||
			(route.getIDeb() == waypoint_2 && route.getIFin() == waypoint_1)) {
			return route;
		}
	}
	return Route(-1, -1, -1); // Si la route n'existe pas
}

/**
 * @brief Fonction pour vérifier les voisins
 * @param voisins Liste d'indices des voisins
 * @param deja_vu Liste d'indices des waypoints déjà visités
 * @param wrong_way Liste d'indices des waypoints considérés comme mauvais chemins
 */
void Graphe::checkVoisins(std::vector<int> &voisins, std::vector<int> &deja_vu, std::vector<int> &wrong_way)
{
	for (auto &voisin: voisins) {
		// Vérification et suppression du voisin si déjà vu ou mauvais chemin
		if (std::find(deja_vu.begin(), deja_vu.end(), voisin) != deja_vu.end()) {
			voisins.erase(std::remove(voisins.begin(), voisins.end(), voisin), voisins.end());
		} else if (std::find(wrong_way.begin(), wrong_way.end(), voisin) != wrong_way.end()) {
			voisins.erase(std::remove(voisins.begin(), voisins.end(), voisin), voisins.end());
		}
	}
}

/**
 * @brief Fonction pour récupérer l'indice du voisin le plus proche
 * @param voisins Liste d'indices des voisins
 * @param waypoint Indice du waypoint actuel
 * @return Indice du voisin le plus proche
 */
int Graphe::minVoisin(std::vector<int> &voisins, int waypoint)
{
	int min = 0;
	for (std::vector<int>::size_type i = 0; i < voisins.size(); i++) {
		if (this->distance(voisins[i], waypoint) < this->distance(voisins[min], waypoint)) {
			min = i;
		}
	}
	return voisins[min];
}

/**
 * @brief Fonction pour calculer la distance totale d'un chemin
 * @param chemin Chemin à calculer
 * @return Distance totale du chemin
 */
int Graphe::distTot(std::vector<Route> chemin)
{
	int dist = 0;
	for (auto &route: chemin) {
		dist += route.getDistance();
	}
	return dist;
}

/**
 * @brief Fonction pour récupérer l'indice d'un waypoint à partir de son nom
 * @param nom Nom du waypoint
 * @return Indice du waypoint
 */
int Graphe::getWaypointID(std::string nom)
{
	std::vector<Waypoint *> waypoints = this->carte.getWaypoints();
	for (std::vector<Waypoint *>::size_type i = 0; i < waypoints.size(); i++) {
		if (waypoints[i]->getNom() == nom) {
			return i;
		}
	}
	return -1;
}