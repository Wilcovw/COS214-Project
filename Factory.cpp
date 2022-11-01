#include "Factory.h"

Vehicles *Factory::createVehicle(string model, Area *location, double HP, double damage, double speed) {
    return new Vehicles(model, location, HP, damage, speed);
}

void Factory::setVehicle(Vehicles *v) {
    vehicle=v;
}

Vehicles *Factory::getVehicle() {
    return vehicle;
}

void Factory::destroy() {
    delete this;
}

Infrastructure *Factory::clone() {
    return new Factory(HP, location);
}