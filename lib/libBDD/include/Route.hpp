#ifndef ROUTE_HPP
#define ROUTE_HPP

/* Importation des headers nécessaires */
#include <string>
#include <iostream>

/* Classe Route */
class Route
{

private:
    int i_deb;
    int i_fin;
    int distance;

public:
    Route(int i_deb, int i_fin, int distance);
    ~Route(){};
    int getIDeb();
    int getIFin();
    int getDistance();
    std::string getInfos();
    void affiche();

};

#endif // ROUTE_HPP