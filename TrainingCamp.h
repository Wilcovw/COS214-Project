#ifndef TRAININGCAMP_H
#define TRAININGCAMP_H
#include "Troops.h"
#include "Citizens.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Soldiers.h"

class TrainingCamp : public Infrastructure
{
protected:
    vector<Troops *> troops;

public:
    TrainingCamp(double, Area *);
    virtual ~TrainingCamp(){};
    void addTroop(Troops *theTroops);
    bool removeTroop(Troops *theTroops);
    Troops **getTroops();
    virtual void destroy() = 0;
    virtual Infrastructure *clone(Area *) = 0;
    virtual Troops *startDrafting(Citizens *, theTroopTypes) = 0;
};

#endif