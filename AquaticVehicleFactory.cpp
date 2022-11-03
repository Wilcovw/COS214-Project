#include "AquaticVehicleFactory.h"

AquaticVehicleFactory::AquaticVehicleFactory(double hp, Area *area) : Factory(hp, area) {
    type = ::iAquaticFactory;
}

Vehicles *AquaticVehicleFactory::createVehicle(double HP, double damage, double speed) {
    Vehicles *v = new AquaticVehicles(location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void AquaticVehicleFactory::destroy() {
    delete this;
}

Infrastructure *AquaticVehicleFactory::clone() {
    return new AquaticVehicleFactory(getHP(), getArea());
}