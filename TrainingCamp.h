#ifndef TRAININGCAMP_H
#define TRAININGCAMP_H
#include "Troops.h"
#include "Citizens.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Soldiers.h"

class TrainingCamp : public Infrastructure {
protected:
    Troops **troops;
    int numTroops;
public:
    TrainingCamp(double, Area*);
    virtual ~TrainingCamp(){};
    virtual void addTroop(Troops *theTroops) = 0;
    virtual bool removeTroop(Troops *theTroops) = 0;
    virtual Troops** getTroops() = 0;
    virtual void destroy();
};

#endif