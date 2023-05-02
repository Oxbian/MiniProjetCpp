#include "Contour.hpp"

/**
 * @brief Constructeur du Contour
 * @param p1 Point 1 du contour
 * @param p2 Point 2 du contour
 */
Contour::Contour(Point p1, Point p2)
{
	this->points.push_back(p1);
	this->points.push_back(p2);
}

/**
 * @brief Getter des points du contour
 * @return Les points du contour
 */
std::vector<Point> Contour::getPoints()
{
	return this->points;
}

/**
 * @brief Ajout d'un point au contour
 * @param point Point à ajouter
 */
void Contour::ajoutUnPoint(Point point)
{
	this->points.push_back(point);
}