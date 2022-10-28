//
// Created by wilco on 2022/10/16.
//

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
