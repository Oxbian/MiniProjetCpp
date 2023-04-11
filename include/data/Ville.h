#ifndef VILLE_HPP
#define VILLE_HPP

#include <iostream>
#include <string>

using namespace std;

class Ville
{
private:
    /* data */
    string code_postal;
    int nb_habitants;
    string site;
public:
    Ville(/* args */);
    string getSite();
    bool isVille();
    string getInfos();
    void affiche();
    ~Ville();
};


#endif // VILLE_HPP
// test