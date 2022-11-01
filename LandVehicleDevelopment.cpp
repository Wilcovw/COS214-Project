#include "LandVehicleDevelopment.h"

void LandVehicleDevelopment::destroy(){
    delete this;
}

Infrastructure *LandVehicleDevelopment::clone() {
    return new LandVehicleDevelopment(HP, location);
}