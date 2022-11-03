#include "Aircraft.h"

Aircraft::Aircraft(Area* location, double hp, double damage, double speed) : Vehicles(location, hp, damage, speed) {
    type = "Aircraft";
}

void Aircraft::update() {
    this->incLevel();
}

void Aircraft::readyToUpgrade(ResearchAndDevelopmentCentre *r) {
    r->addToList(this);
}

void Aircraft::destroy() {
    delete this;
}

Vehicles *Aircraft::clone() {
    return new Aircraft(getLocation(), getHP(), getDamage(), getSpeed());
}