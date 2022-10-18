//
// Created by wilco on 2022/10/16.
//

#include "LandVehicleDevelopment.h"

void LandVehicleDevelopment::startDeveloping(LandVehicles *v){
    vehicleToBeUpgraded=v;
    if(v != NULL)
        v->incLevel();

}