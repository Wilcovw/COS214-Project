#ifndef GENERALS_CPP
#define GENERALS_CPP
#include "Generals.h"
#include "Medics.cpp"
#include "Soldiers.cpp"

//VALUES TO BE CHANGED
Generals::Generals() : TroopType(15, 15, 15) {
    type = ::theGenerals;
}

Generals::~Generals() {
}

TroopType* Generals::changeType(theTroopTypes theType) {
    if(theType != ::theGenerals) {
        if(theType == ::theMedics) {
            return new Medics();
        } else if(theType == ::theSoldiers) {
            return new Soldiers();
        }
    }
    return this;
}
#endif