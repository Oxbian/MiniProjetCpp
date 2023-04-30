#include "Route.hpp"

/**
 * @brief Constructeur de la Route
 * @param i_deb Identifiant du point de départ
 * @param i_fin Identifiant du point d'arrivée
 * @param distance Distance entre les deux points
 */
Route::Route(int i_deb, int i_fin, int distance)
{
    this->i_deb = i_deb;
    this->i_fin = i_fin;
    this->distance = distance;
}

/**
 * @brief Getter de l'identifiant du point de départ
 * @return L'identifiant du point de départ
 */
int Route::getIDeb()
{
    return this->i_deb;
}

/**
 * @brief Getter de l'identifiant du point d'arrivée
 * @return L'identifiant du point d'arrivée
 */
int Route::getIFin()
{
    return this->i_fin;
}

/**
 * @brief Getter de la distance entre les deux points
 * @return La distance entre les deux points
 */
int Route::getDistance()
{
    return this->distance;
}

/**
 * @brief Getter des informations de la route
 * @return Les informations de la route
 */
std::string Route::getInfos()
{
    return "Route: \nIndice de départ: " + std::to_string(this->i_deb) 
    + "\nIndice d'arrivé: " + std::to_string(this->i_fin) + "\nDistance: " 
    + std::to_string(this->distance);
}

/**
 * @brief Affiche les informations de la route
 */
void Route::affiche()
{
    std::cout << this->getInfos() << std::endl;
}