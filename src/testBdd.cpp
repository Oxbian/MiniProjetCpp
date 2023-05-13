#include "Bdd.hpp"
#include "Graphe.hpp"

int main (int argc, char *argv[]) 
{
	try {
		Bdd bdd("tcp://localhost:3306", "miniprojet", "miniprojet", "miniprojet");
		
		Carte carte = bdd.creerCarte();
		std::cout << "Carte créée" << std::endl;
		carte.affiche();

		Graphe graphe(carte);
		std::cout << "Graphe créé" << std::endl;
		std::cout << "Calcul du plus court chemin entre: " << carte.getWaypoints()[0]->getNom() << " et " << carte.getWaypoints()[42]->getNom() << std::endl;
		std::vector<Route> chemin = graphe.plus_court_chemin(0, 42);
		std::cout << "Plus court chemin calculé" << std::endl;
		for (auto &route : chemin) {
			std::cout << route.getInfos() << std::endl;
		}
		std::cout << "Distance : " << graphe.distTot(chemin) << std::endl;

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	} catch(...){
		std::cout << "Exception non trappée" <<std::endl;
	}
	return EXIT_SUCCESS;
}