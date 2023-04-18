#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>
#include <QObject>

class SceneCarte: public QGraphicsScene
{
    Q_OBJECT

public:
    SceneCarte();
    virtual ~SceneCarte() {};
};

#endif // SCENE_HPP