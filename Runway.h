#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Runway : public Infrastructure{
    private:
        string name;
        Edge flights[];
    public:
        Runway(Area destination);
        void addConnection(Area destination);
        void destroy();
};

#endif