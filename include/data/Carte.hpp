#ifndef CARTE_HPP
#define CARTE_HPP

#include "Ville.h"
#include "Waypoint.h"
#include "Route.h"
#include "Contour.h"

class Carte
{
private:
    /* data */
public:
    Carte(/* args */);
    Contour getContour();
    float getEchelleLon();
    vector<Waypoint*> getWaypoints();
    vector<Route> getRoutes();
    vector<string> getnomsVilles();
    void ajoutUnWaypoint(Waypoint);
    void ajoutUneRoute(Route);
    void insereUneVille(Ville*);
    void affiche();
    ~Carte();
};


#endif // CARTE_HPP
// test