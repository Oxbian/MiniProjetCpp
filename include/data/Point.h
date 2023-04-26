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
    float getLon(){
        return lon;
    };

    float getLat(){
        return lat;
    };
    ~Point(){};
};


#endif // POINT_HPP
// test