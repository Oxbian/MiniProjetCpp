#include "Point.hpp"

/**
 * @brief Constructeur du Point
 * @param num Identifiant du point
 * @param lon Longitude du point
 * @param lat Latitude du point
 */
Point::Point(int num, float lon, float lat)
{
    this->num = num;
    this->lon = lon;
    this->lat = lat;
}

/**
 * @brief Getter de la longitude du point
 * @return La longitude du point
 */
float Point::getLon()
{
    return this->lon;
}

/**
 * @brief Getter de la latitude du point
 * @return La latitude du point
 */
float Point::getLat()
{
    return this->lat;
}