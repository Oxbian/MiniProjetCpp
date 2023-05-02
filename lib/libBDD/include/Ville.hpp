#ifndef VILLE_HPP
#define VILLE_HPP

/* Importation des headers nécessaires */
#include "Waypoint.hpp"
#include <string>
#include <iostream>

/* Classe Ville */
class Ville : public Waypoint
{

private:
    std::string code_postal;
    int nb_habitants;
    std::string site;

public:
    Ville(Waypoint waypoint, std::string code_postal, int nb_habitants, std::string site);
    virtual ~Ville(){};
    std::string getSite();
    bool isVille() override;
    std::string getInfos();
    void affiche();
   
};

#endif // VILLE_HPP