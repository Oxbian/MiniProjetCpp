#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
    /* data */
    int num;
    float lon;
    float lat;
public:
    Point(/* args */);
    float getLon();
    float getLat();
    ~Point();
};


#endif // POINT_HPP
// test