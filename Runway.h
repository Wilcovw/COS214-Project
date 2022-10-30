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
    vector<Edge> flights;

public:
    Runway(Area *destination, string name, double hp);
    void addConnection(Area *destination, string name);
    void destroy();
};

#endif