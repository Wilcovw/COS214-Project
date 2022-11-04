#ifndef AIRFORCETRAINING_CPP
#define AIRFORCETRAINING_CPP
#include "Generals.h"
#include "SpecialForces.h"
#include "Soldiers.h"
#include "AirforceTraining.h"

AirforceTraining::AirforceTraining(double theHP, Area* theLocation) : TrainingCamp(theHP, theLocation) {
    type = ::iAirforceCamp;
}

AirforceTraining::~AirforceTraining() {
    
}

Troops* AirforceTraining::startDrafting(Citizens* c, theTroopTypes type) {
    Troops* newTroops = nullptr;
    if (c->getStatus() == "Enlisted") {
        if (type == ::theGenerals)
        {
            newTroops = new Airforce(this->location, new Generals(), c);
        }
        else if (type == ::theSpecialForces)
        {
            newTroops = new Airforce(this->location, new SpecialForces(), c);
        }
        else
        {
            newTroops = new Airforce(this->location, new Soldiers(), c);
        }
        c->changeStatus();
        return newTroops;
    }
    return newTroops;
}

void AirforceTraining::destroy() {
    delete this;
}

Infrastructure* AirforceTraining::clone(Area* newArea) {
    AirforceTraining* clone = new AirforceTraining(HP, newArea);
    for(auto t : troops) {
        if(t->getClone() != nullptr) {
            clone->addTroop(t->getClone());
        }
    }
    return clone;
}

#endif