#include "LandVehicleFactory.h"

LandVehicleFactory::LandVehicleFactory(double hp, Area *area) : Factory(hp, area)
{
    type = ::iLandFactory;
}

Vehicles *LandVehicleFactory::createVehicle(double HP, double damage, double speed)
{
    Vehicles *v = new LandVehicles(location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void LandVehicleFactory::destroy()
{
    delete this;
}

Infrastructure *LandVehicleFactory::clone(Area *newArea)
{
    return new LandVehicleFactory(getHP(), newArea);
}