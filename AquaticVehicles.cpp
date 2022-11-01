#include "AquaticVehicles.h"

AquaticVehicles::AquaticVehicles(string model, Area* location, double hp, double damage, double speed) : Vehicles(model, location, hp, damage,speed) {
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

Vehicles *AquaticVehicles::clone() {
    return new AquaticVehicles(getModel(), getLocation(), getHP(), getDamage(), getSpeed());
}