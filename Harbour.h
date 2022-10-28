#ifndef HARBOUR_H
#define HARBOUR_H

#include <vector>
#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Harbour : public Infrastructure{
    public:
        Harbour(Area *destination, string name);
        addConnection(Area destination);
        destroy();
    private:
        string name;
        vector<Edge> connectedHarbours;
};
#endif