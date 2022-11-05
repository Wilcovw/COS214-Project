#ifndef SPECIALFORCE_CPP
#define SPECIALFORCE_CPP
#include "SpecialForces.h"
#include "Soldiers.h"
#include "Generals.h"

//VALUES TO BE CHANGED
SpecialForces::SpecialForces() : TroopType(20,30, 15) {
    type = ::theSpecialForces;
}


SpecialForces::~SpecialForces() {
    
}

TroopType* SpecialForces::changeType(theTroopTypes theType) {
    if(theType != ::theSpecialForces) {
        if(theType == ::theSoldiers) {
            return new Soldiers();
        } else if(theType == ::theGenerals) {
            return new Generals();
        }
    }
    return this;
}

#endif