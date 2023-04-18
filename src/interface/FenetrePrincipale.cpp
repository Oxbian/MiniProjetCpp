#include "FenetrePrincipale.hpp"

/**
 * @brief Contructeur de la FenetrePrincipale
 * @param parent 
 */
FenetrePrincipale::FenetrePrincipale(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Itinéraire");
    this->setMinimumSize(WIDTH, HEIGHT);

    /*  Layout & widget de la fenêtre principale */
    central_widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout();
    central_widget->setLayout(layout);
    this->setCentralWidget(central_widget);

    /* Ajout des éléments de la fenêtre, avec la scène et les vues */
    this->scene = new SceneCarte();
    this->great_view = new GrandeVue(this->scene, this, 1);
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
 * @return 
 */
QGroupBox *FenetrePrincipale::createLeftSide()
{
    QGroupBox *group = new QGroupBox();
	group->setMaximumWidth(WIDTH/3);

	QVBoxLayout *vbox = new QVBoxLayout;
	group->setLayout(vbox);

	QLabel *depart_label = new QLabel("Ville de départ");
    this->depart_edit = new QLineEdit();

	QLabel *arrivee_label = new QLabel("Ville d'arrivée");
    this->arrivee_edit = new QLineEdit();

    this->calculate_btn = new QPushButton("Calculer");

	this->small_view = new MiniVue(this->scene, this);

	vbox->addWidget(depart_label);
	vbox->addWidget(this->depart_edit);
	vbox->addWidget(arrivee_label);
	vbox->addWidget(this->arrivee_edit);
    vbox->addWidget(this->calculate_btn);
	vbox->addWidget(this->small_view);

	return group;
}

/**
 * @brief Fonction pour afficher les coordonnées de notre zone zoomée
 * @param pos 
 */
void FenetrePrincipale::affiche_pos_scene(QPointF pos)
{
    QString msg = "Coordonnées scène ("
        + QString::number(pos.x(),'f',2) + ","
        + QString::number(pos.y(),'f',2) + ")";
    this->barre_status->showMessage(msg);
}

/**
 * @brief Fonction pour calculer la distance entre deux points et affiché le chemin
 * le plus court
 */
void FenetrePrincipale::calculate_dist()
{
    QString depart_nom = this->depart_edit->text();
    QString arrivee_nom = this->arrivee_edit->text();
    QMessageBox::information(this, "info", "Vous avez recherchez la distance " 
    + depart_nom + " - " + arrivee_nom, QMessageBox::Ok);
    // Appellé la fonction de calcul entre les deux villes
}