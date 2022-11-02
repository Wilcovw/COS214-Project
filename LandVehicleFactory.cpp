#include "LandVehicleFactory.h"

LandVehicleFactory::LandVehicleFactory(double hp, Area *area) : Factory(hp, area) {
    type = ::iLandFactory;
}

Vehicles *LandVehicleFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new LandVehicles(model, location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void LandVehicleFactory::destroy() {
    delete this;
}

Infrastructure *LandVehicleFactory::clone() {
    return new LandVehicleFactory(getHP(), getArea());
}