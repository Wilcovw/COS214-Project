#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Road : public Infrastructure
{
private:
    Edge **theRoad = new Edge *[2];
    double distance;
public:
    Road(Area*, Area *, double);
    virtual void destroy();
};

#endif