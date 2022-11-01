#include "AquaticVehicleFactory.h"

Vehicles *AquaticVehicleFactory::createVehicle(string model, Area* location, double HP, double damage, double speed) {
    Vehicles *v = new AquaticVehicles(model, location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void AquaticVehicleFactory::destroy() {
    delete this;
}

Infrastructure *AquaticVehicleFactory::clone() {
    return new AquaticVehicleFactory(getHP(), getArea());
}