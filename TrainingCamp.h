#ifndef TRAININGCAMP_H
#define TRAININGCAMP_H
#include "Troops.h"

class TrainingCamp
{
protected:
    Troops **troops;
    int numTroops;

public:
    TrainingCamp(){};
    virtual ~TrainingCamp(){};
    void addTroop(Troops *theTroops);
    bool removeTroop(Troops *theTroops);
};

#endif