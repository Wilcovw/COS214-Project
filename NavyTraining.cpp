#ifndef NAVYTRAINING_CPP
#define NAVYTRAINING_CPP
#include "NavyTraining.h"

NavyTraining::NavyTraining(double HP, Area* location) : TrainingCamp(HP, location) {
    
}

NavyTraining::~NavyTraining() {
    
}

void NavyTraining::addTroop(Troops *theTroops) {

}

bool NavyTraining::removeTroop(Troops *theTroops) {
    return false;
}

Troops** NavyTraining::getTroops() {
    return this->troops;
}

void NavyTraining::startTraining() {

}

Troops* NavyTraining::startDrafting(Citizens* c) {
    Troops* newTroops = nullptr;
    if (c->getStatus() == "Enlisted") {
        newTroops = new Navy(this->location, new Soldiers(), c);
        c->changeStatus();
        return newTroops;
    }
    
    return newTroops;
}

#endif