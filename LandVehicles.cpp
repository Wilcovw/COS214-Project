#include "LandVehicles.h"

LandVehicles::LandVehicles(string model, Area* location, double hp, double damage, double speed) : Vehicles(model, location, hp, damage, speed) {
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
    return new LandVehicles(getModel(), getLocation(), getHP(), getDamage(), getSpeed());
}