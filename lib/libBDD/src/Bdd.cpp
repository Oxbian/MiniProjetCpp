#include "Bdd.hpp"

/**
 * @brief Constructeur de la Bdd
 * @param host Adresse de la base de donnée
 * @param database Nom de la base de donnée
 * @param user Utilisateur ayant accès à la base de donnée
 * @param password Mot de passe de l'utilisateur
 */
Bdd::Bdd(std::string host, std::string database, std::string user, std::string password)
{
    this->driver = get_driver_instance();
    this->conn = this->driver->connect(host, user, password);

    // Connect to the mysql database
    this->conn->setSchema(database);
    setlocale(LC_ALL, "C");
}

/**
 * @brief Destructeur de la Bdd
 */
Bdd::~Bdd()
{
    std::cout << "Fermeture connection\n" << std::endl; 
    delete this->conn;
}

/**
 * @brief Fonction pour créer un objet contour à partir de la base de donnée
 * @return Le contour créé
*/
Contour Bdd::creerContour()
{
    sql::Statement *stmt = this->conn->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM contour");
    Contour contour;
    while (res->next()) {
        Point pt (res->getInt(1), res->getDouble(2), res->getDouble(3));
        contour.ajoutUnPoint(pt);
    }
    delete res;
    delete stmt;
    return contour;
}

/**
 * @brief Fonction pour créer une liste de waypoints à partir de la base de donnée
 * @return Liste de pointeurs de waypoints créée
 */
std::vector<Waypoint *> Bdd::creerWaypoints()
{
    sql::Statement *stmt = this->conn->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM waypoint");
    std::vector<Waypoint*> waypoints;
    while (res->next()) {
        waypoints.push_back(new Waypoint(res->getString(1), res->getDouble(2), res->getDouble(3)));
    }
    delete res;
    delete stmt;
    return waypoints;
}

/**
 * @brief Fonction pour créer une liste de villes à partir de la base de donnée
 * @param waypoints Liste de pointeurs de waypoints
 */
void Bdd::creerVilles(std::vector<Waypoint *> waypoints)
{
    sql::Statement *stmt = this->conn->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM waypoint");
    while (res->next()) {
        std::string nom = res->getString(1);
        int id = getId(nom, waypoints);
        if (id == -1) {
            std::cout << "Erreur : ville non trouvée" << std::endl;
            return;
        }
        std::cout << "Id: " << id << std::endl;
        Ville *ville = new Ville(*(waypoints.at(id)), nom, res->getInt(2), res->getString(3));
        waypoints.at(id) = ville;
    }
}

/**
 * @brief Fonction pour créer une liste de route à partir de la base de donnée
 * @param waypoints Liste de pointeurs de waypoints
 * @return Liste de route créée
 */
std::vector<Route> Bdd::creerRoute(std::vector<Waypoint *> waypoints)
{
    sql::Statement *stmt = this->conn->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM route");
    std::vector<Route> routes;
    while (res->next()) {
        int i_depart = getId(res->getString(1), waypoints);
        int i_arrivee = getId(res->getString(2), waypoints);
        if (i_depart == -1 || i_arrivee == -1) {
            std::cout << "Erreur : route non trouvée" << std::endl;
            return routes;
        }
        Route route (i_depart, i_arrivee, res->getInt(3));
        routes.push_back(route);
    }
    delete res;
    delete stmt;
    return routes;
}

/**
 * @brief Fonction pour créer une carte à partir de la base de donnée
 * @return Carte créée
 */
Carte Bdd::creerCarte()
{
    std::vector<Waypoint *> waypoints = creerWaypoints();
    creerVilles(waypoints);
    std::vector<Route> routes = creerRoute(waypoints);
    Contour contour = creerContour();
    Carte carte (waypoints, routes, contour);
    return carte;
}

/**
 * @brief Fonction pour récupérer l'id d'un waypoint à partir de son nom
 * @param nom Nom du waypoint recherché
 * @param waypoints Liste de pointeurs de waypoints
 * @return Id du waypoint recherché
 */
int Bdd::getId(std::string nom, std::vector<Waypoint *> waypoints)
{
    for (unsigned int i = 0; i < waypoints.size(); i++) {
        if (waypoints[i]->getNom() == nom) {
            return i;
        }
    }
    return -1;
}