#ifndef CONTOUR_HPP
#define CONTOUR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Point.h"

using namespace std;

class Contour
{
private:
    /* data */
public:
    Contour(/* args */);
    vector<Point> getPoints();
    void ajoutUnPoint(Point);
    ~Contour();
};


#endif // CONTOUR_HPP
// test