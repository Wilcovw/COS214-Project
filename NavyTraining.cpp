#ifndef NAVYTRAINING_CPP
#define NAVYTRAINING_CPP
#include "NavyTraining.h"
#include "Generals.h"
#include "SpecialForces.h"
#include "Soldiers.h"

NavyTraining::NavyTraining(double HP, Area* location) : TrainingCamp(HP, location) {
    type = ::iNavyCamp;
}

NavyTraining::~NavyTraining() {
    
}

Troops* NavyTraining::startDrafting(Citizens* c, theTroopTypes type) {
    Troops* newTroops = nullptr;
    if (c->getStatus() == "Enlisted") {
        if (type == ::theGenerals)
        {
             newTroops = new Navy(this->location, new Generals(), c);
        }
        else if (type == ::theSpecialForces)
        {
             newTroops = new Navy(this->location, new SpecialForces(), c);
        }
        else
        {
            newTroops = new Navy(this->location, new Soldiers(), c);
        }
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