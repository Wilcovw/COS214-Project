#ifndef GROUNDTROOPTRAINING_P
#define GROUNDTROOPTRAINING_P
#include "GroundTroopTraining.h"
#include "Soldiers.h"
#include "Generals.h"
#include "SpecialForces.h"

GroundTroopTraining::GroundTroopTraining(double theHP, Area *theLocation) : TrainingCamp(theHP, theLocation)
{
    type = ::iGroundCamp;
}

GroundTroopTraining::~GroundTroopTraining()
{
}

Troops *GroundTroopTraining::startDrafting(Citizens *c, theTroopTypes type)
{
    Troops *newTroops = nullptr;
    if (c->getStatus() == "Enlisted")
    {
        if (type == ::theGenerals)
        {
            newTroops = new GroundTroops(this->location, new Generals(), c);
        }
        else if (type == ::theSpecialForces)
        {
            newTroops = new GroundTroops(this->location, new SpecialForces(), c);
        }
        else
        {
            newTroops = new GroundTroops(this->location, new Soldiers(), c);
        }
        c->changeStatus();
        return newTroops;
    }
    return newTroops;
}

void GroundTroopTraining::destroy()
{
    delete this;
}

Infrastructure *GroundTroopTraining::clone(Area *newArea)
{
    GroundTroopTraining *clone = new GroundTroopTraining(HP, newArea);
    for (auto t : troops)
    {
        if (t->getClone() != nullptr)
        {
            clone->addTroop(t->getClone());
        }
    }
    return clone;
}
#endif