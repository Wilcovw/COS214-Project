#include "AquaticVehicleDevelopment.h"

AquaticVehicleDevelopment::AquaticVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area)
{
    type = ::iAquaticDevelopment;
}

void AquaticVehicleDevelopment::destroy()
{
    delete this;
}

Infrastructure *AquaticVehicleDevelopment::clone(Area *newArea)
{
    return new AquaticVehicleDevelopment(HP, newArea);
}