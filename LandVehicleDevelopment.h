#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "LandVehicles.h"

class LandVehicleDevelopment : ResearchAndDevelopmentCentre
{
public:
    LandVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area){};
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
