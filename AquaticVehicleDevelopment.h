#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "AquaticVehicles.h"

class AquaticVehicleDevelopment : ResearchAndDevelopmentCentre
{
public:
    AquaticVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area){};
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H