//
// Created by wilco on 2022/10/16.
//

#include "AquaticVehicleDevelopment.h"

void AquaticVehicleDevelopment::startDeveloping(AquaticVehicles *v){
    vehicleToBeUpgraded=v;
    if(v != NULL)
        v->incLevel();
}