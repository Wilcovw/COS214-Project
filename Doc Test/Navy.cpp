#ifndef NAVY_CPP    
#define NAVY_CPP
#include "Navy.h"

//Values to be changed
Navy::Navy(Area* theLocation, TroopType* theType, Citizens* theCitizen) : Troops(0, theLocation, theType, theCitizen) {
    kind = ::tNavy;
}

Navy::~Navy() {
    
}

#endif