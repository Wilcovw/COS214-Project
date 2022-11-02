#include "LandVehicleDevelopment.h"

LandVehicleDevelopment::LandVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area) {
    type = ::iLandDevlopment;
}

void LandVehicleDevelopment::destroy(){
    delete this;
}

Infrastructure *LandVehicleDevelopment::clone() {
    return new LandVehicleDevelopment(HP, location);
}