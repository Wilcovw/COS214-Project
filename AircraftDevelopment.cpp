#include "AircraftDevelopment.h"

AircraftDevelopment::AircraftDevelopment(double hp, Area *area) : ResearchAndDevelopmentCentre(hp, area)
{
    type = ::iAircraftDevelopment;
}

void AircraftDevelopment::destroy()
{
    delete this;
}

Infrastructure *AircraftDevelopment::clone(Area *newArea)
{
    return new AircraftDevelopment(HP, newArea);
}
