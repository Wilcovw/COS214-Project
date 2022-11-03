#include "LandVehicles.h"

LandVehicles::LandVehicles(Area* location, double hp, double damage, double speed) : Vehicles(location, hp, damage, speed) {
    type = "Land Vehicle";
}

void LandVehicles::update() {
    this->incLevel();
}

void LandVehicles::readyToUpgrade(ResearchAndDevelopmentCentre *r) {
    r->addToList(this);
}

void LandVehicles::destroy() {
    delete this;
}

Vehicles *LandVehicles::clone() {
    return new LandVehicles(getLocation(), getHP(), getDamage(), getSpeed());
}