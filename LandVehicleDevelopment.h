#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "LandVehicles.h"

class LandVehicleDevelopment : public ResearchAndDevelopmentCentre
{
public:
    LandVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area){};
    void destroy();
    Infrastructure* clone();
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
