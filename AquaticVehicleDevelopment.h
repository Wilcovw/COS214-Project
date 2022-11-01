#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "AquaticVehicles.h"

class AquaticVehicleDevelopment : public ResearchAndDevelopmentCentre
{
public:
    AquaticVehicleDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area){};
    void destroy();
    Infrastructure* clone();
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
