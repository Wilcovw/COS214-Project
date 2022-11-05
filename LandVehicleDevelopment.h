#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "LandVehicles.h"

class LandVehicleDevelopment : public ResearchAndDevelopmentCentre
{
public:
	/**
	 * @brief Construct a new Land Vehicle Development object
	 * 
	 * @param hp Health of Centre
	 * @param area The Area which the Centre is located in
	 */
    LandVehicleDevelopment(double hp, Area *area);
	/**
	 * @brief Destroy the current Centre
	 * 
	 */
    void destroy();
	/**
	 * @brief Makes a copy of the current Centre
	 * 
	 * @return Infrastructure* 
	 */
    Infrastructure* clone();
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
