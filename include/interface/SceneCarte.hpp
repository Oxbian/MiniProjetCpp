#ifndef SCENE_HPP
#define SCENE_HPP

/* Importation des headers nécessaires */
#include <QGraphicsScene>
#include <QObject>
#include "Carte.hpp"

/* Classe SceneCarte */
class SceneCarte: public QGraphicsScene
{
    Q_OBJECT

public:
    SceneCarte(Carte &carte);
    virtual ~SceneCarte() {};
    void creerScene(Carte &carte);
};

#endif // SCENE_HPP