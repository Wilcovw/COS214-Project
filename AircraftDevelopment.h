#ifndef FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "Aircraft.h"

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
	Infrastructure *clone();
};

#endif // FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
