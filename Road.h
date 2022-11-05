#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "Infrastructure.h"
using namespace std;

class Edge;
class Road : public Infrastructure
{
private:
    Edge **edges = new Edge *[2];
public:
    Road(Area*, Area *, double, double);
    ~Road();
    virtual void destroy();
    virtual Infrastructure* clone(Area* newArea);
};

#endif