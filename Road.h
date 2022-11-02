#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Road : public Infrastructure
{
private:
    Edge **theRoad = new Edge *[2];
public:
    Road(Area*, Area *, double, double);
    virtual void destroy();
    virtual Infrastructure* clone(Area* newArea);
};

#endif