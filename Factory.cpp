#include "Factory.h"

void Factory::setVehicle(Vehicles *v) {
    vehicle=v;
}

Vehicles *Factory::getVehicle() {
    return vehicle;
}

void Factory::destroy() {
    delete this;
}