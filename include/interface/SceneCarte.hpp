#ifndef SCENE_HPP
#define SCENE_HPP

/* Importation des headers nécessaires */
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QMessageBox>

#include <QObject>
#include <string>
#include <typeinfo>
#include "Carte.hpp"
#include "Point.hpp"
#include "Ville.hpp"

/* Constantes */
const float TAILLE_POINT = 0.025;

/* Classe SceneCarte */
class SceneCarte: public QGraphicsScene
{
    Q_OBJECT

public:
    SceneCarte(Carte &carte);
    virtual ~SceneCarte(){};

public:
    void draw_map(Carte &carte);
    void draw_path(std::vector<Route> chemin, Carte &carte);

private:
    static std::map<std::string, QColor> tab_couleurs;

};

#endif // SCENE_HPP