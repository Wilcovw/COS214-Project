#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include <vector>
#include "Infrastructure.h"

using namespace std;

class Runway : public Infrastructure
{
private:
    string name;
    vector<Edge*> flights;
    double distance;
public:
    Runway(Area *, double, double);
    void addConnection(Area *destination);
    virtual void destroy();
    virtual Infrastructure* clone(Area* newArea);
};

#endif