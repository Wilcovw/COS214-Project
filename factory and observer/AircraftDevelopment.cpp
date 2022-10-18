//
// Created by wilco on 2022/10/16.
//

#include "AircraftDevelopment.h"

void AircraftDevelopment::startDeveloping(Aircraft *v){
    vehicleToBeUpgraded=v;
    if(v != NULL)
        v->incLevel();
}