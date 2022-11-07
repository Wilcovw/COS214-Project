#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "AquaticVehicles.h"
/**
 * @brief AquaticVehicleDevelopment inherrits from ResearchAndDevelopmentCentre and is used to upgrade navy vehicles
 *
 */
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
	/**
	 * @brief Destroys the current Research And Development centre
	 *
	 */
	void destroy();
	/**
	 * @brief Makes a copy of the current Research And Development Centre
	 *
	 * @return Infrastructure*
	 */
	virtual Infrastructure *clone(Area *newArea);
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
