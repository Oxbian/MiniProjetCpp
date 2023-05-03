#ifndef CONTOUR_HPP
#define CONTOUR_HPP

/* Importation des headers nécessaires */
#include <vector>

#include "Point.hpp"

/* Classe Contour */
class Contour
{

private:
	std::vector<Point> points;

public:
	Contour(){};
	Contour(Point p1, Point p2);
	~Contour(){};

public:
	std::vector<Point> getPoints();
	void ajoutUnPoint(Point point);

};

#endif // CONTOUR_HPP