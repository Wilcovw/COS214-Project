#ifndef MEDICS_CPP
#define MEDICS_CPP
#include "Medics.h"
#include "Soldiers.cpp"
#include "Generals.cpp"

//VALUES TO BE CHANGED
Medics::Medics() : TroopType(15,15, 15) {
    type = ::theMedics;
}


Medics::~Medics() {
    
}

TroopType* Medics::changeType(theTroopTypes theType) {
    if(theType != ::theMedics) {
        if(theType == ::theSoldiers) {
            return new Soldiers();
        } else if(theType == ::theGenerals) {
            return new Generals();
        }
    }
    return this;
}

#endif