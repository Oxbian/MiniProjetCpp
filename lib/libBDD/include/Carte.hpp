#ifndef CARTE_HPP
#define CARTE_HPP

/* Importation des headers nécessaires */
#include <vector>
#include <string>
#include <cmath>

#include "Ville.hpp"
#include "Waypoint.hpp"
#include "Route.hpp"
#include "Contour.hpp"

/* Classe Carte */
class Carte
{

private:
    Contour contour;
    std::vector<Waypoint *> waypoints;
    std::vector<Route> routes;

public:
    Carte(std::vector<Waypoint *> waypoints, std::vector<Route> routes, Contour contour);
    Carte(Waypoint *waypoint_1, Waypoint *waypoint_2, Route route, Contour contour);
    Carte(){};
    ~Carte(){};

public:
    Contour getContour();
    float getEchelleLon();
    std::vector<Waypoint *> getWaypoints();
    std::vector<Route> getRoutes();
    std::vector<std::string> getnomsVilles();
    void ajoutUnWaypoint(Waypoint waypoint);
    void ajoutUneRoute(Route route);
    void insereUneVille(Ville *ville);
    void affiche();
};

#endif // CARTE_HPP