#ifndef GENERALS_CPP
#define GENERALS_CPP
#include "Generals.h"
#include "SpecialForces.h"
#include "Soldiers.h"

//VALUES TO BE CHANGED
Generals::Generals() : TroopType(10, 50, 5) {
    type = ::theGenerals;
}

Generals::~Generals() {
}

TroopType* Generals::changeType(theTroopTypes theType) {
    if(theType != ::theGenerals) {
        if(theType == ::theSpecialForces) {
            return new SpecialForces();
        } else if(theType == ::theSoldiers) {
            return new Soldiers();
        }
    }
    return this;
}
#endif