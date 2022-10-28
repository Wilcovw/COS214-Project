#ifndef SOLDIERS_CPP
#define SOLDIERS_CPP
#include "Soldiers.h"
#include "Medics.cpp"
#include "Generals.cpp"

//VALUES TO BE CHANGED
Soldiers::Soldiers() : TroopType(15, 15, 15) {
    type = ::theSoldiers;
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