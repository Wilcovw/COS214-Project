#ifndef AIRFORCE_CPP    
#define AIRFORCE_CPP
#include "Airforce.h"

//Values to be changed
Airforce::Airforce(Area* theLocation, TroopType* theType, Citizens* theCitizens) : Troops(0, theLocation, theType, theCitizens) {

}

Airforce::~Airforce() {

}

#endif