#ifndef GROUNDTROOPS_CPP    
#define GROUNDTROOPS_CPP
#include "GroundTroops.h"

//Values to be changed
GroundTroops::GroundTroops(Area* theLocation, TroopType* theType, Citizens* theCitizen) : Troops(theType->getMaxHP(), theLocation, theType, theCitizen) {
    
}

GroundTroops::~GroundTroops() {

}

#endif