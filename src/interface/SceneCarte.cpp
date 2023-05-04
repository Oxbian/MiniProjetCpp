#include "SceneCarte.hpp"

/**
 * @brief Tableau de couleur pour l'affichage des points
 */
std::map<std::string, QColor> SceneCarte::tab_couleurs = {
    {"rouge", Qt::red},
    {"bleu", Qt::blue},
    {"vert", Qt::green},
    {"jaune", Qt::yellow},
    {"magenta", Qt::magenta},
    {"cyan", Qt::cyan},
    {"gris", Qt::gray},
    {"noir", Qt::black},
    {"blanc", Qt::white},
    {"transparent", Qt::transparent}
};

/**
 * @brief Constructeur de SceneCarte
 * @param carte Carte à dessiner dans la scène
 */
SceneCarte::SceneCarte(Carte &carte):QGraphicsScene()
{
    this->creerContour(carte);
}

void SceneCarte::creerContour(Carte &carte)
{
    carte.affiche();

    qreal epais = 0; // Epaisseur des traits
    std::string text_tooltip;

    /* Dessin du contour de la carte */
    QColor couleur = tab_couleurs["vert"];
    int nb_points = carte.getContour().getPoints().size();
    if (nb_points == 0) {
        return;
    }
    std::vector<Point> points = carte.getContour().getPoints();
    QGraphicsLineItem *ligne = nullptr;
    Point point_prec = points[0];

    for (auto &point : points) {
        ligne = new QGraphicsLineItem(0, 0, point.getLat()-point_prec.getLat(), point.getLon()-point_prec.getLon());
        ligne->setPos(point_prec.getLat(), point_prec.getLon());
        ligne->setPen(QPen(couleur, epais, Qt::SolidLine));
        this->addItem(ligne);
        point_prec = point;
    }

    /*
    for (int i = 0; i < nb_points-1; i++) {
        std::cout << "Point: " << i << std::endl;
        ligne = new QGraphicsLineItem(points[i].getLat(), points[i].getLon(),
         points[i+1].getLat(), points[i+1].getLon());
        ligne->setPen(QPen(couleur, epais));
        this->addItem(ligne);

        QGraphicsEllipseItem *point = new QGraphicsEllipseItem( -epais/2, -epais/2, epais, epais);
        point->setPos(points[i].getLat(), points[i].getLon());
        point->setPen(QPen(couleur, epais, Qt::SolidLine));
        point->setBrush(QBrush(couleur, Qt::SolidPattern));
        point->setParentItem(ligne);
    }
    std::cout << "Dernier Point" << std::endl;
    // Dernier point
    QGraphicsEllipseItem *point = new QGraphicsEllipseItem( -epais/2, -epais/2, epais, epais);
    point->setPos(points[nb_points-1].getLat(), points[nb_points-1].getLon());
    point->setPen(QPen(couleur, epais, Qt::SolidLine));
    point->setBrush(QBrush(couleur, Qt::SolidPattern));

    point->setParentItem(ligne);
    */
	qreal taille_o = epais;
	QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
	origine->setPos(0,0);
	origine->setPen(QPen(Qt::black,0,Qt::SolidLine));
	this->addItem(origine);
}