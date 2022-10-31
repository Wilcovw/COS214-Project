#ifndef HARBOUR_H
#define HARBOUR_H

#include <vector>
#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Harbour : public Infrastructure
{
public:
    Harbour(Area *, double);
    void addConnection(Area *destination);
    virtual void destroy();

private:
    string name;
    vector<Edge*> connectedHarbours;
};
#endif