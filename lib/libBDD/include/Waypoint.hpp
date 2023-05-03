#ifndef WAYPOINT_HPP
#define WAYPOINT_HPP

/* Importation des headers nécessaires */
#include <string>
#include <iostream>

/* Classe Waypoint */
class Waypoint
{

private:
    std::string nom;
    float lon;
    float lat;

public:
    Waypoint(std::string nom, float lon, float lat);
    virtual ~Waypoint(){};

public:
    std::string getNom();
    float getLon();
    float getLat();
    virtual bool isVille();
    std::string getInfos();
    void affiche();

};

#endif // WAYPOINT_HPP