#include "MiniVue.hpp"

/**
 * @brief Constructeur de MiniVue
 * @param scene Scène à afficher dans la minivue
 * @param w Pointeur vers le widget parent
 */
MiniVue::MiniVue(SceneCarte *scene, QWidget *w): QGraphicsView(scene, w)
{
    Q_UNUSED(scene);
    scale(1, -1); // Inversion des Y
}

/**
 * @brief Fonction qui s'assure que lors du zoom on l'affichage reste dans la fenêtre
 * @param event Event de resize
 */
void MiniVue::resizeEvent(QResizeEvent *event)
{
    if (this->transform().m11() == 1) {
        this->fitInView(sceneRect(), Qt::KeepAspectRatio);
    }
}

/**
 * @brief Fonction qui dessine la zone de zoom de Grande Vue
 * @param painter Painter pour dessiner
 * @param zoomed_zone Zone de zoom de Grande Vue
 */
void MiniVue::drawForeground(QPainter *painter, const QRectF &zoomed_zone)
{
    painter->setPen(QPen(Qt::black, 0));
    painter->drawRect(this->zoomed_zone);
}

/**
 * @brief Signal qui récupère la zone de zoom de Grande Vue
 * @param zoomed_zone 
 */
void MiniVue::draw_viewport(QRectF zoomed_zone)
{
    this->zoomed_zone = zoomed_zone;
    viewport()->update();
}