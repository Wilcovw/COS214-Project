#ifndef MEMENTO_H
#define MEMENTO_H
#include "WarHistory.h"
#include "WarEngine.h"

using namespace std;
class WarMap;
class WarPhase;

class Memento{
private:
    friend class WarEngine;
    Memento(vector<Country*>, vector<Area*>, WarMap map);
    WarPhase* warphase;
public:
    virtual ~Memento();
    void print();
};

#endif