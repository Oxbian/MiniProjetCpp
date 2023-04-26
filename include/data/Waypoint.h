#ifndef WAYPOINT_HPP
#define WAYPOINT_HPP

#include <iostream>
#include <string>

using namespace std;

class Waypoint
{
private:
    /* data */
    string nom;
    float lon;
    float lat;
public:
    Waypoint(/* args */);
    string getNom(){
        return nom;
    };
    float getLon(){
        return lon;
    };
    float getLat(){
        return lat;
    };
    virtual bool isVille();
    string getInfos();
    void affiche();
    ~Waypoint(){};
};


#endif // WAYPOINT_HPP
// test