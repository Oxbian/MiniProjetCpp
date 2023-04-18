#ifndef GRANDEVUE_HPP
#define GRANDEVUE_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QObject>

#include "SceneCarte.hpp"

class GrandeVue: public QGraphicsView
{
    Q_OBJECT

public:
    GrandeVue(SceneCarte *scene, QWidget *w, int orientation_nord);
    virtual ~GrandeVue() {};

signals:
    void zoom_changed(QRectF zoomed_zone);
    void zoom_position(QPointF zoomed_pos);

private:
    // Gestionnaire d'évènements
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void drawForeground(QPainter *painter, const QRectF &) override;
    void drawBackground(QPainter *painter, const QRectF &) override;

private:
    int orientation_nord;
};

#endif // GRANDEVUE_HPP