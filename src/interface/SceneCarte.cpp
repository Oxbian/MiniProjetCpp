#include "SceneCarte.hpp"

/**
 * @brief Constructeur de SceneCarte
 * @param carte Carte à dessiner dans la scène
 */
SceneCarte::SceneCarte(Carte &carte)
{
    // Ajout des points de la carte, des routes, etc
    creerScene(carte);
}

/**
 * @brief Création de la scène grâce aux données de la carte
 * @param carte Carte à dessiner dans la scène
 */
void SceneCarte::creerScene(Carte &carte)
{
    carte.affiche();
}