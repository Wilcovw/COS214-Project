#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "AquaticVehicles.h"

class AquaticVehicleDevelopment : public ResearchAndDevelopmentCentre
{
public:
	/**
	 * @brief Construct a new Aquatic Vehicle Development object
	 * 
	 * @param hp The Health of the Centre
	 * @param area The Area the centre is located in
	 */
    AquaticVehicleDevelopment(double hp, Area *area);
    void destroy();
    Infrastructure* clone();
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
