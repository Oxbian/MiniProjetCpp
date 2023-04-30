#ifndef POINT_HPP
#define POINT_HPP

/* Classe Point */
class Point
{

private:
    int num;
    float lon;
    float lat;

public:
    Point(int num, float lon, float lat);
    ~Point(){};

    float getLon();
    float getLat();

};

#endif // POINT_HPP