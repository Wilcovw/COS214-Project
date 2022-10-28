#ifndef GROUNDTROOPS_CPP    
#define GROUNDTROOPS_CPP
#include "GroundTroops.h"

//Values to be changed
GroundTroops::GroundTroops(Area* theLocation, TroopType* theType) : Troops(theType->getMaxHP(), theLocation, theType) {
    
}

GroundTroops::~GroundTroops() {

}

#endif