#ifndef FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "Aircraft.h"
/**
 * @brief AircraftDevelopment inherits from ResearchAndDevelopmentCentre and is used to upgrade aircrafts
 *
 */
class AircraftDevelopment : public ResearchAndDevelopmentCentre
{
public:
	/**
	 * @brief Construct a new Aircraft Development object
	 *
	 * @param hp The health of the Centre
	 * @param area The Area where the centre is int
	 */
	AircraftDevelopment(double hp, Area *area);
	/**
	 * @brief Destroy the current centre
	 *
	 */
	void destroy();
	/**
	 * @brief Makes a copy of the current centre
	 *
	 * @return Infrastructure*
	 */
	virtual Infrastructure *clone(Area *newArea);
};

#endif // FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
