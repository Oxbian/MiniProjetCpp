#include "Waypoint.hpp"

/**
 * @brief Constructeur du Waypoint
 * @param nom Nom du waypoint
 * @param lon Longitude du waypoint
 * @param lat Latitude du waypoint
 */
Waypoint::Waypoint(std::string nom, float lon, float lat)
{
    this->nom = nom;
    this->lon = lon;
    this->lat = lat;
}

/**
 * @brief Getter du nom du waypoint
 * @return Nom du waypoint
 */
std::string Waypoint::getNom()
{
    return this->nom;
}

/**
 * @brief Getter de la longitude du waypoint
 * @return Longitude du waypoint
 */
float Waypoint::getLon()
{
    return this->lon;
}

/**
 * @brief Getter de la latitude du waypoint
 * @return Latitude du waypoint
 */
float Waypoint::getLat()
{
    return this->lat;
}

/**
 * @brief Vérifie si le waypoint est une ville
 * @return Booléen indiquant si le waypoint est une ville
 */
bool Waypoint::isVille()
{
    return false;
}

/**
 * @brief Récupère les informations du waypoint
 * @return Informations du waypoint
 */
std::string Waypoint::getInfos()
{
    return "Waypoint:\nNom: " + this->nom + "\nLongitude: " + std::to_string(this->lon) + "\nLatitude: " + std::to_string(this->lat);
}

/**
 * @brief Affiche les informations du waypoint
 */
void Waypoint::affiche()
{
    std::cout << this->getInfos() << std::endl;
}