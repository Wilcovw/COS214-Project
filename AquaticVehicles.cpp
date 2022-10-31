#include "AquaticVehicles.h"

AquaticVehicles::AquaticVehicles(string model, double hp, double damage, double speed) : Vehicles(model, hp, damage,speed) {
    type = "Aquatic Vehicle";
}

void AquaticVehicles::update() {
    this->incLevel();
}

void AquaticVehicles::readyToUpgrade(ResearchAndDevelopmentCentre *r) {
    r->addToList(this);
}

void AquaticVehicles::destroy() {
    delete this;
}