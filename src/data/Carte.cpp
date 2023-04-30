#include "Carte.hpp"

/**
 * @brief Constructeur de la carte
 * @param waypoint_1 Waypoint 1 de la carte
 * @param waypoint_2 Waypoint 2 de la carte
 * @param route Route de la carte
 * @param contour Contour de la carte
 */
Carte::Carte(Waypoint *waypoint_1, Waypoint *waypoint_2, Route route, Contour contour)
{
    this->waypoints.push_back(waypoint_1);
    this->waypoints.push_back(waypoint_2);
    this->routes.push_back(route);
    this->contour = contour;
}

/**
 * @brief Constructeur de la carte
 * @param waypoints Liste de waypoints de la carte
 * @param routes Liste de route de la carte
 * @param contour Contour de la carte
 */
Carte::Carte(std::vector<Waypoint *> waypoints, std::vector<Route> routes, Contour contour)
{
    this->waypoints = waypoints;
    this->routes = routes;
    this->contour = contour;
}

/**
 * @brief Getter du contour de la carte
 * @return Contour de la carte
 */
Contour Carte::getContour()
{
    return this->contour;
}

/**
 * @brief Getter de l'échelle en longitude
 * @return L'échelle en longitude
 */
float Carte::getEchelleLon()
{
    return 0;
}

/**
 * @brief Getter des waypoints de la carte
 * @return Vecteur de pointeur de waypoints
 */
std::vector<Waypoint *> Carte::getWaypoints()
{
    return this->waypoints;
}

/**
 * @brief Getter des routes de la carte
 * @return Vecteur de routes
 */
std::vector<Route> Carte::getRoutes()
{
    return this->routes;
}

/**
 * @brief Getter des noms des villes de la carte
 * @return Vecteur de noms de villes
 */
std::vector<std::string> Carte::getnomsVilles()
{
    std::vector<std::string> noms_villes;
    for (Waypoint *waypoint : this->waypoints)
    {
        if (waypoint->isVille())
        {
            noms_villes.push_back(waypoint->getNom());
        }
    }
    return noms_villes;
}

/**
 * @brief Ajoute un waypoint à la carte
 * @param waypoint Waypoint à ajouter
 */
void Carte::ajoutUnWaypoint(Waypoint waypoint)
{
    this->waypoints.push_back(&waypoint);
}

/**
 * @brief Ajoute une route à la carte
 * @param route Route à ajouter
 */
void Carte::ajoutUneRoute(Route route)
{
    this->routes.push_back(route);
}

/**
 * @brief Insère une ville dans la carte
 * @param ville Ville à insérer
 */
void Carte::insereUneVille(Ville *ville)
{
    this->waypoints.push_back(ville);
}

/**
 * @brief Affiche les informations de la carte
 */
void Carte::affiche()
{
    std::cout << "Carte:" << std::endl;
    std::cout << "Contour:" << std::endl;
    for (Point point : this->contour.getPoints())
    {
        std::cout << "Point:\n" << "Latitude: " << point.getLat() << "\nLongitude: " << point.getLon() << std::endl;
    }
    std::cout << "Waypoints:" << std::endl;
    for (Waypoint *waypoint : this->waypoints)
    {
        waypoint->affiche();
    }
    std::cout << "Routes:" << std::endl;
    for (Route route : this->routes)
    {
        route.affiche();
    }
}