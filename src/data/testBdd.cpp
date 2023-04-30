#include "Bdd.hpp"

int main (int argc, char *argv[]) 
{
	try {
		Bdd bdd("localhost", "miniprojet", "miniprojet", "miniprojet");
		Carte carte = bdd.creerCarte();
		carte.affiche();
	}
	catch (sql::SQLException &e) {
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	catch(...){
		std::cout << "Exception non trappée"<<std::endl;
	}

	return EXIT_SUCCESS;
}