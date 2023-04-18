#include "GrandeVue.hpp"

/**
 * @brief Constructeur de GrandeVue
 * @param scene 
 * @param w 
 * @param orientation_nord 
 */
GrandeVue::GrandeVue(SceneCarte *scene, QWidget *w, int orientation_nord): 
QGraphicsView(scene, w), orientation_nord(orientation_nord)
{
    Q_UNUSED(scene);
    scale(1, -1); // Inversion des Y
    setMouseTracking(true);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate); // Permet d'update la flèche du nord
}

/**
 * @brief Fonction qui s'assure que lors du zoom on l'affichage reste dans la fenêtre
 * @param event 
 */
void GrandeVue::resizeEvent(QResizeEvent *event)
{
    if (this->transform().m11() == 1) {
        this->fitInView(sceneRect(), Qt::KeepAspectRatio);
    }
}

/**
 * @brief Fonction qui gère l'event de zoom
 * @param event 
 */
void GrandeVue::wheelEvent(QWheelEvent *event) 
{
    int angle = event->angleDelta().y();
    qreal facteur_zoom = 1;
    if (angle > 0) {
        facteur_zoom = 1.1;
    } else {
        facteur_zoom = 0.9;
    }
    centerOn(mapToScene(event->pos()));
    scale(facteur_zoom, facteur_zoom);
}

/**
 * @brief Fonction qui permet d'avoir la taille de la zone zoomée
 * @param event 
 */
void GrandeVue::paintEvent(QPaintEvent *event)
{
    QPolygonF poly = mapToScene(viewport()->x(), viewport()->y(), viewport()->width(),
    viewport()->height());
    QRectF rect_viewport = poly.boundingRect();

    emit zoom_changed(rect_viewport);

    // re-propage l'évènement
    QGraphicsView::paintEvent(event);
}

/**
 * @brief Fonction qui permet d'avoir la position de la zone zoomée
 * @param event 
 */
void GrandeVue::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pos_scene = mapToScene(event->pos());
    emit zoom_position(pos_scene);

    // re-propage l'évènement
    QGraphicsView::mouseMoveEvent(event);
}

/**
 * @brief Fonction pour dessiner la flèche d'orientation sur la carte
 * @param painter 
 * @param zoomed_zone 
 */
void GrandeVue::drawBackground(QPainter *painter, const QRectF &)
{
    painter->setWorldMatrixEnabled(false); // mettre en coords View (pixels)
    // Chargement image et rotation selon orientation plan
    QPixmap pixmap("assets/image/north.png");
    QTransform matrice;
    matrice.rotate(orientation_nord);
    QPixmap pixmap2 = pixmap.transformed(matrice);

    painter->drawPixmap(viewport()->x(), viewport()->y(), pixmap2);
    painter->setWorldMatrixEnabled(true);
}

/**
 * @brief Fonction pour dessiner l'échelle sur la carte
 * @param painter 
 * @param  
 */
void GrandeVue::drawForeground(QPainter *painter, const QRectF &)
{
    painter->setWorldMatrixEnabled(false);// mettre en coords View (pixels)
    painter->setPen(QPen(Qt::black, 0));
    qreal echelle = this->transform().m11();
    int x2 = viewport()->x()+viewport()->width()-10;
    int y2 = viewport()->y()+viewport()->height()-10;
    int x1 = x2 - echelle;
    int y1 = y2;
    int longueur_tick = qMin(static_cast<int>(echelle/10),5);
    painter->drawLine(x1,y1,x2,y2);
    painter->drawLine(x1,y1-longueur_tick,x1,y1+longueur_tick);
    painter->drawLine(x2,y2-longueur_tick,x2,y2+longueur_tick);
    QRectF rect_texte(x1, y1-30, x2-x1, 20 );
    painter->drawText(rect_texte, Qt::AlignCenter|Qt::TextDontClip,"1 m");
    painter->setWorldMatrixEnabled(true);
}