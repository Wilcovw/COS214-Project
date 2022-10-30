#ifndef FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "Aircraft.h"

class AircraftDevelopment : public ResearchAndDevelopmentCentre
{
public:
    AircraftDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area){};
};

#endif // FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
