#ifndef HARBOUR_H
#define HARBOUR_H
#include <list>
#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Edge;
class Harbour : public Infrastructure
{
private:
    string name;
    list<Edge*> edges;

public:
    Harbour(Area *, double);
    ~Harbour();
    void addConnection(Area* destination, double distance, Harbour* otherHarbour);
    void removeConnection(Area* destination, Harbour* otherHarbour, Edge* path);
    virtual void destroy();
    virtual Infrastructure* clone(Area* newArea);
};


#endif