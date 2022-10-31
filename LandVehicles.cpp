#include "LandVehicles.h"

LandVehicles::LandVehicles(string model, double hp, double damage, double speed) : Vehicles(model, hp, damage, speed) {
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