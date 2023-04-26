
#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <iostream>
#include <string>

using namespace std;

class Route
{
private:
    /* data */
    int i_deb;
    int i_fin;
    int distance;
public:
    Route(/* args */);
    int getIDeb(){
        return i_deb;
    };
    int getIFin(){
        return i_fin;
    };
    int getDistance(){
        return distance;
    };
    string getInfos();
    void affiche();
    ~Route(){};
};


#endif // ROUTE_HPP
// test