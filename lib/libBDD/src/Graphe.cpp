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

	// On récupère la matrice d'adjacence
	std::vector<std::vector<int>> matrice = this->createMatrice();
	std::vector<Route> chemin = this->Dijkstra(matrice, waypoint_1, waypoint_2);
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

/**
 * @brief Fonction pour créer la matrice d'adjacence
 * @return Matrice d'adjacence
 */
std::vector<std::vector<int>> Graphe::createMatrice()
{
	std::vector<std::vector<int>> matrice_adjacence;
	std::vector<Waypoint *> waypoints = this->carte.getWaypoints();
	for (std::vector<Waypoint *>::size_type i = 0; i < waypoints.size(); i++) {
		std::vector<int> ligne;
		for (std::vector<Waypoint *>::size_type j = 0; j < waypoints.size(); j++) {
			if (i == j) {
				ligne.push_back(0);
			} else {
				int dist = this->distance(i, j);
				if (dist == -1) {
					ligne.push_back(INFINI);
				} else {
					ligne.push_back(dist);
				}
			}
		}
		matrice_adjacence.push_back(ligne);
	}
	return matrice_adjacence;
}

/**
 * @brief Fonction pour trouvé le chemin le plus court entre 2 waypoints
 * 
 * @param graphe Matrice d'adjacence du graphe
 * @param src Indice du waypoint de départ
 * @param end Indice du waypoint de sortie
 * @return Liste de routes à suivre
 */
std::vector<Route> Graphe::Dijkstra(std::vector<std::vector<int>> &graphe, int src, int end)
{
	std::vector<int> dist;
	std::vector<int> prev;
	std::vector<int> Q;
	std::vector<Route> chemin;

	for (std::vector<std::vector<int>>::size_type i = 0; i < graphe.size(); i++) {
		dist.push_back(INFINI);
		prev.push_back(-1);
		Q.push_back(i);
	}

	dist[src] = 0;

	while (Q.size() != 0) {
		int u = this->minDist(dist, Q);
		Q.erase(std::remove(Q.begin(), Q.end(), u), Q.end());

		if (u == end) {
			break;
		}

		for (std::vector<std::vector<int>>::size_type i = 0; i < graphe.size(); i++) {
			if (std::find(Q.begin(), Q.end(), i) != Q.end()) {
				int alt = dist[u] + graphe[u][i];
				if (alt < dist[i]) {
					dist[i] = alt;
					prev[i] = u;
				}
			}
		}
	}

	int u = end;
	while (prev[u] != -1) {
		chemin.push_back(this->getRoute(u, prev[u]));
		u = prev[u];
	}

	return chemin;
}

/**
 * @brief Fonction pour trouver le noeud le plus proche
 * @param dist Vecteur des distances
 * @param Q Vecteur des noeuds non visités
 * @return Indice du noeud le plus proche
 */
int Graphe::minDist(std::vector<int> &dist, std::vector<int> &Q)
{
	int min = Q[0];
	for (std::vector<int>::size_type i = 0; i < Q.size(); i++) {
		if (dist[Q[i]] < dist[min]) {
			min = Q[i];
		}
	}
	return min;
}