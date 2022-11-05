#ifndef WARENGINE_H
#define WARENGINE_H
#include "WarPhase.h"
#include <iostream>
using namespace std;



class Country;
class Relationship;
class Area;
class Infrastructure;
class Troops;
class Vehicles;
class WarEngine
{
private:
    WarPhase *phase;
public:
    WarEngine();
    ~WarEngine();
    void newWarPhase();
    void reverseWarPhase();
    WarPhase* getPhase();

    // Memento *createMemento();
    // list<Country *> getCountryGroup();
    // void setCountryGroup(list<Country *> newCountryGroup);
    // void removeAreaAt(int index);
    // void reinstateMemento(Memento *memento);
};

#endif