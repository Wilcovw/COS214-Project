#ifndef GROUNDTROOPTRAINING_P
#define GROUNDTROOPTRAINING_P
#include "GroundTroopTraining.h"

GroundTroopTraining::GroundTroopTraining(double theHP, Area* theLocation)  : TrainingCamp(theHP, theLocation) {

}

GroundTroopTraining::~GroundTroopTraining() {
    
}

bool GroundTroopTraining::removeTroop(Troops *theTroops) {
    return false;
}

void GroundTroopTraining::addTroop(Troops *theTroops) {

}

Troops** GroundTroopTraining::getTroops() {
    return this->troops;
}

void GroundTroopTraining::startTraining(Troops* theTroops) {
    Troops** temp = troops;
    troops = new Troops * [++numTroops];
    for(int i = 0; i < numTroops - 1; i++) {
        troops[i] = temp[i];
    }
    troops[numTroops - 1] = theTroops;
}

Troops* GroundTroopTraining::startDrafting(Citizens* c) {
    Troops* newTroops = nullptr;
    if (c->getStatus() == "Enlisted") {
        newTroops = new GroundTroops(this->location, new Soldiers(), c);
        c->changeStatus();
        return newTroops;
    }
    
    return newTroops;
}
#endif