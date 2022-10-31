#ifndef GROUNDTROOPTRAINING_P
#define GROUNDTROOPTRAINING_P
#include "GroundTroopTraining.h"

GroundTroopTraining::GroundTroopTraining(double theHP, Area* theLocation)  : TrainingCamp(theHP, theLocation) {

}

GroundTroopTraining::~GroundTroopTraining() {
    
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

void GroundTroopTraining::destroy() {
    delete this;
}

Infrastructure* GroundTroopTraining::clone(Area* newArea) {
    GroundTroopTraining* clone = new GroundTroopTraining(HP, newArea);
    for(auto t : troops) {
        if(t->getClone() != nullptr) {
            clone->addTroop(t->getClone());
        }
    }
    return clone;
}
#endif