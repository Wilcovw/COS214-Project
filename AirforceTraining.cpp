#ifndef AIRFORCETRAINING_CPP
#define AIRFORCETRAINING_CPP
#include "AirforceTraining.h"

AirforceTraining::AirforceTraining(double theHP, Area* theLocation) : TrainingCamp(theHP, theLocation) {

}

AirforceTraining::~AirforceTraining() {

}

Troops* AirforceTraining::startDrafting(Citizens* c) {
    Troops* newTroops = nullptr;
    if (c->getStatus() == "Enlisted") {
        newTroops = new Airforce(this->location, new Soldiers(), c);
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