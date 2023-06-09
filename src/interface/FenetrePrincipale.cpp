#include "FenetrePrincipale.hpp"

/**
 * @brief Contructeur de la FenetrePrincipale
 * @param carte Référence vers la carte à afficher
 * @param parent Pointeur vers le widget parent (null)
 */
FenetrePrincipale::FenetrePrincipale(Carte &carte, Graphe &graphe, QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Itinéraire");
    this->setMinimumSize(WIDTH, HEIGHT);

    /* Récupération des données */
    this->graphe = graphe;
    this->carte = carte;

    /*  Layout & widget de la fenêtre principale */
    central_widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout();
    central_widget->setLayout(layout);
    this->setCentralWidget(central_widget);

    /* Ajout des éléments de la fenêtre, avec la scène et les vues */
    this->scene = new SceneCarte(carte);
    this->great_view = new GrandeVue(this->scene, this, ORIENTATION_NORD);
    layout->addWidget(createLeftSide());
    layout->addWidget(this->great_view);

    this->barre_status = statusBar();

    /* Connection des signaux */
    connect(this->calculate_btn, &QPushButton::clicked, this, &FenetrePrincipale::calculate_dist);
    connect(this->great_view, &GrandeVue::zoom_changed, this->small_view, &MiniVue::draw_viewport);
    connect(this->great_view, &GrandeVue::zoom_position, this, &FenetrePrincipale::affiche_pos_scene);
}

/**
 * @brief Fonction pour construire les éléments de la partie gauche de la fenêtre
 * @return Le groupbox des éléments de la partie gauche de la fenêtre
 */
QGroupBox *FenetrePrincipale::createLeftSide()
{
    /* Récupération des noms de villes pour l'autocomplétion*/
    std::vector<std::string> villes = this->carte.getnomsVilles();
    QStringList wordlist;
    for (auto &ville : villes)
    {
        wordlist << QString::fromStdString(ville);
    }

    /* Création des éléments du GroupBox de la partie gauche */
    QCompleter *completer = new QCompleter(wordlist, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    QGroupBox *group = new QGroupBox();
	group->setMaximumWidth(WIDTH/3);

	QVBoxLayout *vbox = new QVBoxLayout;
	group->setLayout(vbox);

	QLabel *depart_label = new QLabel("Ville de départ");
    this->depart_edit = new QLineEdit();

	QLabel *arrivee_label = new QLabel("Ville d'arrivée");
    this->arrivee_edit = new QLineEdit();

    // Ajout de l'autocomplétion
    this->depart_edit->setCompleter(completer);
    this->arrivee_edit->setCompleter(completer);

    this->calculate_btn = new QPushButton("Calculer");

    this->distance_label = new QLabel("Distance : ");

	this->small_view = new MiniVue(this->scene, this);

	vbox->addWidget(depart_label);
	vbox->addWidget(this->depart_edit);
	vbox->addWidget(arrivee_label);
	vbox->addWidget(this->arrivee_edit);
    vbox->addWidget(this->calculate_btn);
    vbox->addWidget(this->distance_label);
	vbox->addWidget(this->small_view);

	return group;
}

/**
 * @brief Fonction pour afficher les coordonnées de notre zone zoomée
 * @param pos Position à affichée
 */
void FenetrePrincipale::affiche_pos_scene(QPointF pos)
{
    QString msg = "Coordonnées géographique : "
        + convert_deg_to_dms(pos.y(), false) + " "
        + convert_deg_to_dms(pos.x(), true);
    this->barre_status->showMessage(msg);
}

/**
 * @brief Fonction pour calculer la distance entre deux points et affiché le chemin
 * le plus court
 */
void FenetrePrincipale::calculate_dist()
{
    /* Récupération des villes de départ et d'arrivé */
    QString depart_nom = this->depart_edit->text();
    QString arrivee_nom = this->arrivee_edit->text();

    /* Clear de la carte et affichage de la route à suivre + distance */
    this->scene->clear();
	std::vector<Route> chemin = graphe.plus_court_chemin(this->graphe.getWaypointID(depart_nom.toStdString()), this->graphe.getWaypointID(arrivee_nom.toStdString()));
    this->scene->draw_path(chemin, this->carte);
    this->distance_label->setText("Distance : " + QString::number(this->graphe.distTot(chemin)) + " km");
}

/**
 * @brief Fonction pour convertir des degrés en degrés, minutes, secondes
 * @param deg Degrés à convertir
 * @param is_lat Booléen pour savoir si c'est une latitude ou une longitude
 * @return La chaîne de caractère contenant la conversion
 */
QString FenetrePrincipale::convert_deg_to_dms(qreal deg, bool is_lat)
{
    /* Calcul des degrés, minutes et secondes */
    deg = abs(deg);
    int deg_int = static_cast<int>(deg);
    double min = (deg - deg_int) * 60;
    int min_int = static_cast<int>(min);
    double sec = (min - min_int) * 60;
    int sec_int = static_cast<int>(sec);

    /* Vérification si lat ou lon, et ajout des lettres correspondants */
    QString direction = is_lat ? (deg > 0 ? "E" : "W") : (deg > 0 ? "N" : "S");
    
    return QString::number(abs(deg_int)) + "°" + QString::number(abs(min_int)) + "." + QString::number(abs(sec_int)) + "\'" + direction;
}