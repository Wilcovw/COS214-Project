#ifndef AIRFORCETRAINING_CPP
#define AIRFORCETRAINING_CPP
#include "AirforceTraining.h"

AirforceTraining::AirforceTraining(double theHP, Area* theLocation) : TrainingCamp(theHP, theLocation) {

}

AirforceTraining::~AirforceTraining() {

}

void AirforceTraining::addTroop(Troops *theTroops) {

}

bool AirforceTraining::removeTroop(Troops *theTroops) {
    return false;
}

Troops** AirforceTraining::getTroops() {
    return this->troops;
}

void AirforceTraining::startTraining() {
    
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
    
}

#endif