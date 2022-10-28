#ifndef AIRFORCE_CPP    
#define AIRFORCE_CPP
#include "Airforce.h"

//Values to be changed
Airforce::Airforce(Area* theLocation, TroopType* theType) : Troops(0, theLocation, theType) {

}

Airforce::~Airforce() {

}

#endif