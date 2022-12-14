#include "LandVehicles.h"

LandVehicles::LandVehicles(Area* location, double hp, double damage, double speed) : Vehicles(location, hp, damage, speed) {
    type = ::landVehicle;
}

LandVehicles::~LandVehicles() {
    
}

void LandVehicles::update() {
    this->incLevel();
}

void LandVehicles::readyToUpgrade(ResearchAndDevelopmentCentre *r) {
    r->addToList(this);
}

Vehicles *LandVehicles::clone() {
    return new LandVehicles(getLocation(), getHP(), getDamage(), getSpeed());
}