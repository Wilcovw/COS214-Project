#include "LandVehicleFactory.h"

<<<<<<< Updated upstream
Vehicles *LandVehicleFactory::createVehicle(string model, Area* location, double HP, double damage, double speed) {
    Vehicles *v = new LandVehicles(model, location, HP, damage, speed);
=======
LandVehicleFactory::LandVehicleFactory(double hp, Area *area) : Factory(hp, area) {
    type = ::iLandFactory;
}

Vehicles *LandVehicleFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new LandVehicles(model, HP, damage, speed);
>>>>>>> Stashed changes
    setVehicle(v);
    return v;
}

void LandVehicleFactory::destroy() {
    delete this;
}

Infrastructure *LandVehicleFactory::clone() {
    return new LandVehicleFactory(getHP(), getArea());
}