#include <QApplication>
#include <QMessageBox>
#include "FenetrePrincipale.hpp"
#include "Bdd.hpp"

int main(int argc, char **argv)
{
	/* Chargemennt de Qt */
    QApplication app(argc, argv);
    Carte carte;

	/* Connexion à la base de données */
    try {
		Bdd bdd("tcp://localhost:3306", "miniprojet", "miniprojet", "miniprojet");
	    carte = bdd.creerCarte();
		std::cout << "Carte créée" << std::endl;
	}
	catch (sql::SQLException &e) {
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	catch(...){
		std::cout << "Exception non trappée" <<std::endl;
	}

	/* Création de la fenêtre et affichage de l'interface */
    FenetrePrincipale mw (carte);
    mw.show();
    return app.exec();
}
