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
class WarEngine
{
private:
    WarPhase *phase;
    WarHistory *history;

public:
    /**
    * @brief Construct a new War Engine object
    * 
    */
    WarEngine();
    /**
     * @brief Destroy the War Engine object
     * 
     */
    ~WarEngine();
    /**
     * @brief Stores a new warPhase in the history* of this class
     * 
     */
    void newWarPhase();
    /**
     * @brief makes the phase variable equal the last saved phase, hence returning one phase
     * 
     */
    void reverseWarPhase();
    /**
     * @brief Get the Phase object
     * 
     * @return WarPhase* 
     */
    WarPhase *getPhase();

};

#endif