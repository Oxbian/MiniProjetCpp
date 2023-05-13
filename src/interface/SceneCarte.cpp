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
    qreal epais = 0; // Epaisseur des traits
    std::string text_tooltip;

    /* Dessin du contour de la carte */
    QColor couleur = tab_couleurs["vert"];
    int nb_points = carte.getContour().getPoints().size();
    if (nb_points == 0) {
        QMessageBox::critical(nullptr, "Erreur", "La carte ne contient pas de points");
        return;
    }

    /* Création du polygon de la carte */
    std::vector<Point> points = carte.getContour().getPoints();
    QPolygonF poly;
    for (auto &point : points) {
        poly << QPointF(point.getLat(), point.getLon());
    }
    this->addPolygon(poly, QPen(Qt::black, epais, Qt::SolidLine), QBrush(couleur, Qt::SolidPattern));

    /* Dessin des waypoints */
    std::vector<Waypoint*> waypoints = carte.getWaypoints();
    for (auto &waypoint : waypoints) {
        if (waypoint->isVille()) { // TODO: vérifier si c'est bien une ville et récupérer les données
            couleur = tab_couleurs["cyan"];
            text_tooltip = waypoint->getInfos();
        } else {
            couleur = tab_couleurs["rouge"];
            text_tooltip = waypoint->getInfos();
        }
        this->addEllipse(waypoint->getLat()-0.0125, waypoint->getLon()-0.0125, 0.025, 0.025, 
        QPen(couleur, epais, Qt::SolidLine), QBrush(couleur, Qt::SolidPattern))->setToolTip(QString::fromStdString(text_tooltip));
    }

    /* Dessin des routes */
    couleur = tab_couleurs["noir"];
    for (auto &route : carte.getRoutes()) {
        text_tooltip = "Route " + waypoints[route.getIDeb()]->getNom() + " - " + waypoints[route.getIFin()]->getNom() + "\nDistance: " + std::to_string(route.getDistance());
        this->addLine(waypoints[route.getIDeb()]->getLat(), waypoints[route.getIDeb()]->getLon(), 
         waypoints[route.getIFin()]->getLat(), waypoints[route.getIFin()]->getLon(), 
         QPen(couleur, epais, Qt::SolidLine))->setToolTip(QString::fromStdString(text_tooltip));
    }
}

/**
 * @brief Fonction pour dessiner le chemin à prendre
 * @param chemin Chemin à dessiner
 * @param carte Référence vers la carte
 */
void SceneCarte::draw_path(std::vector<Route> chemin, Carte &carte)
{
    this->creerContour(carte);
    qreal epais = 0.025; // Epaisseur des traits
    QColor couleur = tab_couleurs["rouge"];
    std::string text_tooltip;
    
    std::vector<Waypoint*> waypoints = carte.getWaypoints();
    for (auto &route : chemin) {
        text_tooltip = "Route " + waypoints[route.getIDeb()]->getNom() + " - " + waypoints[route.getIFin()]->getNom() + "\nDistance: " + std::to_string(route.getDistance());
        this->addLine(waypoints[route.getIDeb()]->getLat(), waypoints[route.getIDeb()]->getLon(), 
         waypoints[route.getIFin()]->getLat(), waypoints[route.getIFin()]->getLon(), 
         QPen(couleur, epais, Qt::SolidLine))->setToolTip(QString::fromStdString(text_tooltip));
    }
}