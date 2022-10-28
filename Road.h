#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Road : public Infrastructure{
    private:
        string name;
        Edge *theRoad;
    public:
        Road(Area *destination, string name);
        void destroy();
};

#endif