#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include "Infrastructure.h"
#include <vector>

using namespace std;

class Runway : public Infrastructure{
    private:
        string name;
        vector<Edge> flights;
    public:
        Runway(Area *destination, string name);
        void addConnection(Area *destination, string name);
        void destroy();
};

#endif