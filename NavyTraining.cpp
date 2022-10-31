#ifndef NAVYTRAINING_CPP
#define NAVYTRAINING_CPP
#include "NavyTraining.h"

NavyTraining::NavyTraining(double HP, Area* location) : TrainingCamp(HP, location) {
    
}

NavyTraining::~NavyTraining() {
    
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

void NavyTraining::destroy() {
    delete this;
}

Infrastructure* NavyTraining::clone(Area* newArea) {
    NavyTraining* clone = new NavyTraining(HP, newArea);
    for(auto t : troops) {
        if(t->getClone() != nullptr) {
            clone->addTroop(t->getClone());
        }
    }
    return clone;
}

#endif