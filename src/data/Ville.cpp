#include "Ville.hpp"

/**
 * @brief Constructeur de la ville
 * @param waypoint Waypoint de la ville
 * @param code_postal Code postal de la ville
 * @param nb_habitants Nombre d'habitants de la ville
 * @param site Page wikipédia de la ville
 */
Ville::Ville(Waypoint waypoint, std::string code_postal, int nb_habitants, std::string site): Waypoint(waypoint.getNom(), waypoint.getLon(), waypoint.getLat())
{
    this->code_postal = code_postal;
    this->nb_habitants = nb_habitants;
    this->site = site;
}

/**
 * @brief Getter du site de la ville
 * @return Le site de la ville
 */
std::string Ville::getSite()
{
    return this->site;
}

/**
 * @brief Vérifie si le waypoint est une ville
 * @return true si le waypoint est une ville, false sinon
 */
bool Ville::isVille()
{
    return true;
}

/**
 * @brief Récupère les informations de la ville
 * @return Les informations de la ville
 */
std::string Ville::getInfos()
{
    return "Ville:\nNom: " + this->getNom() + "\nCode postal: " 
    + this->code_postal + "\nNombre d'habitants: " + std::to_string(this->nb_habitants) 
    + "\nSite: " + this->site + "\n";
}

/**
 * @brief Affiche les informations de la ville
 */
void Ville::affiche()
{
    std::cout << this->getInfos() << std::endl;
}
