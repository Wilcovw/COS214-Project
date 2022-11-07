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
class WarHistory;
/**
 * @brief WarEngine allows a user to create and handle mementos of the phase of the war and through phase the rest of the system
 *
 */
class WarEngine
{
private:
    WarPhase *phase;
    WarHistory *history;

public:
    WarEngine();
    ~WarEngine();
    void newWarPhase();
    void reverseWarPhase();
    WarPhase *getPhase();
};

#endif