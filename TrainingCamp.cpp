#ifndef TRAININGCAMP_CPP
#define TRAININGCAMP_CPP
#include "TrainingCamp.h"
#include "GroundTroopTraining.h"
#include "NavyTraining.h"
#include "AirforceTraining.h"

TrainingCamp::TrainingCamp(double theHP, Area *theLocation) : Infrastructure(theHP, theLocation)
{
}

void TrainingCamp::addTroop(Troops *theTroops)
{
    troops.push_back(theTroops);
}

bool TrainingCamp::removeTroop(Troops *theTroops)
{
    std::vector<Troops *>::iterator it;
    for (it = troops.begin(); it != troops.end(); ++it)
    {
        if (theTroops == *it)
        {
            troops.erase(it);
            return true;
        }
    }
    return false;
}

void TrainingCamp::destroy()
{
}

Infrastructure *TrainingCamp::clone(Area *newArea)
{
    return nullptr;
}

Troops *TrainingCamp::startDrafting(Citizens *)
{
    return nullptr;
}

#endif