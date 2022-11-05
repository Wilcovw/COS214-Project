#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include <list>
#include "Infrastructure.h"
using namespace std;

class Edge;
class Runway : public Infrastructure
{
private:
    string name;
    list<Edge*> edges;
public:
    Runway(Area *, double);
    ~Runway();
    void addConnection(Area *destination, double distance, Runway* otherRunway);
    void removeConnection(Area* destination, Runway* otherRunway, Edge* path);
    virtual void destroy();
    virtual Infrastructure* clone(Area* newArea);
};

#endif