#ifndef HARBOUR_H
#define HARBOUR_H

#include <vector>
#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Harbour : public Infrastructure
{
public:
    Harbour(Area *, double, double);
    void addConnection(Area *destination);
    virtual void destroy();

private:
    string name;
    double distance;
    vector<Edge*> connectedHarbours;
    virtual Infrastructure* clone(Area* newArea);
};
#endif