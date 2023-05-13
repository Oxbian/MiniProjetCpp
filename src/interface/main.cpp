#include "FenetrePrincipale.hpp"
#include "LoginDialog.hpp"
#include "Bdd.hpp"

int main(int argc, char **argv)
{
	/* Chargemennt de Qt */
    QApplication app(argc, argv);
	LoginDialog dlg;
    Carte carte;

	/* Ouverture de la boite de dialogue de login à la BDD */
	std::string host, database, username, password;
	if (dlg.exec()) {
		dlg.getResult(host, database, username, password);
	} else {
		std::cout << "Erreur lors de l'ouverture de la boite de dialogue de login à la BDD" << std::endl;
		return -1;
	}

	/* Connexion à la base de données */
    try {
		Bdd bdd("tcp://" + host + ":3306", database, username, password);
	    carte = bdd.creerCarte();
		std::cout << "Carte créée" << std::endl;
		std::cout << "Graphe créé" << std::endl;
	} catch (sql::SQLException &e) {
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	} catch(...){
		std::cout << "Exception non trappée" <<std::endl;
	}

	Graphe graphe(carte);

	/* Création de la fenêtre et affichage de l'interface */
    FenetrePrincipale mw (carte, graphe);
    mw.show();
    return app.exec();
}
