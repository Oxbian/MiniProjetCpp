#ifndef SCENE_HPP
#define SCENE_HPP

/* Importation des headers nécessaires */
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QMessageBox>

#include <QObject>
#include <string>
#include "Carte.hpp"
#include "Point.hpp"

/* Classe SceneCarte */
class SceneCarte: public QGraphicsScene
{
    Q_OBJECT

public:
    SceneCarte(Carte &carte);
    virtual ~SceneCarte(){};

public:
    void creerContour(Carte &carte);

private:
    static std::map<std::string, QColor> tab_couleurs;

};

#endif // SCENE_HPP