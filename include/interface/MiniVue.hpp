#ifndef MINIVUE_HPP
#define MINIVUE_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QObject>

#include "SceneCarte.hpp"

class MiniVue: public QGraphicsView
{
    Q_OBJECT
public:
    MiniVue(SceneCarte *scene, QWidget *w);
    virtual ~MiniVue() {};
private:
    void resizeEvent(QResizeEvent *event) override;
    void drawForeground(QPainter *painter, const QRectF &) override;
public slots:
    void draw_viewport(QRectF zoomed_zone);

private:
    QRectF zoomed_zone;
};

#endif // MINIVUE_HPP