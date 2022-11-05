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
    /**
     * @brief Constructor that sets the warphase with given parameters
     * @param allCountries
     * @param c
     * @param map
     */
    Memento(vector<Country*> allCountries, Communication* c, WarMap* map);
    /**
     * @brief Stores the previous war phase
     */
    WarPhase* warphase;
public:
    /**
     * @brief virtual destructor of Memento
     */
    virtual ~Memento();
};

#endif