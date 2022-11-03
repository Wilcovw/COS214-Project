#include "AquaticVehicles.h"

AquaticVehicles::AquaticVehicles(Area* location, double hp, double damage, double speed) : Vehicles(location, hp, damage,speed) {
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
    return new AquaticVehicles(getLocation(), getHP(), getDamage(), getSpeed());
}