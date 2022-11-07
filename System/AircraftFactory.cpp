#include "AircraftFactory.h"

AircraftFactory::AircraftFactory(double hp, Area *area) : Factory(hp, area)
{
    type = ::iAircraftFactory;
}

Vehicles *AircraftFactory::createVehicle(double HP, double damage, double speed)
{
    Vehicles *v = new Aircraft(location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void AircraftFactory::destroy()
{
    delete this;
}

Infrastructure *AircraftFactory::clone(Area *newArea)
{
    return new AircraftFactory(getHP(), newArea);
}