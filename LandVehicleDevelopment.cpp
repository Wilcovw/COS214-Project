#include "LandVehicleDevelopment.h"

LandVehicleDevelopment::LandVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area)
{
    type = ::iLandDevelopment;
}

void LandVehicleDevelopment::destroy()
{
    delete this;
}

Infrastructure *LandVehicleDevelopment::clone(Area *newArea)
{
    return new LandVehicleDevelopment(HP, newArea);
}