#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Waypoint.h"
#include "Route.h"

using namespace std;

class Graphe
{
private:
    /* data */
    string nom;
    float lon;
    float lat;
public:
    Graphe(/* args */);
    vector<Waypoint> voisins(Waypoint);
    float distance(Waypoint pt1, Waypoint pt2);
    vector<Route> plus_court(Waypoint pt1, Waypoint pt2);
    ~Graphe();
};


#endif // GRAPHE_HPP
// test