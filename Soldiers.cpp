#ifndef SOLDIERS_CPP
#define SOLDIERS_CPP
#include "Soldiers.h"
#include "Medics.h"
#include "Generals.h"

//VALUES TO BE CHANGED
Soldiers::Soldiers() : TroopType(15, 15, 15) {
    type = ::theSoldiers;
}

Soldiers::~Soldiers() {
    
}

TroopType* Soldiers::changeType(theTroopTypes theType) {
    if(theType != ::theSoldiers) {
        if(theType == ::theMedics) {
            return new Medics();
        } else if(theType == ::theGenerals) {
            return new Generals();
        }
    }
    return this;
}
#endif