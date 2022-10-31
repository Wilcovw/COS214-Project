#include "AquaticVehicleFactory.h"

Vehicles *AquaticVehicleFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new AquaticVehicles(model, HP, damage, speed);
    setVehicle(v);
    return v;
}

void AquaticVehicleFactory::destroy() {
    delete this;
}