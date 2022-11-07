#include "AquaticVehicles.h"

AquaticVehicles::AquaticVehicles(Area *location, double hp, double damage, double speed) : Vehicles(location, hp, damage, speed)
{
    type = ::aquaticVehicle;
}

void AquaticVehicles::update()
{
    this->incLevel();
}

void AquaticVehicles::readyToUpgrade(ResearchAndDevelopmentCentre *r)
{
    r->addToList(this);
}

AquaticVehicles::~AquaticVehicles() 
{

}

Vehicles *AquaticVehicles::clone()
{
    return new AquaticVehicles(getLocation(), getHP(), getDamage(), getSpeed());
}