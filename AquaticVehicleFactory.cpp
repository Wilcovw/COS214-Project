#include "AquaticVehicleFactory.h"

<<<<<<< Updated upstream
Vehicles *AquaticVehicleFactory::createVehicle(string model, Area* location, double HP, double damage, double speed) {
    Vehicles *v = new AquaticVehicles(model, location, HP, damage, speed);
=======
AquaticVehicleFactory::AquaticVehicleFactory(double hp, Area *area) : Factory(hp, area) {
    type = ::iAquaticFactory;
}

Vehicles *AquaticVehicleFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new AquaticVehicles(model, HP, damage, speed);
>>>>>>> Stashed changes
    setVehicle(v);
    return v;
}

void AquaticVehicleFactory::destroy() {
    delete this;
}

Infrastructure *AquaticVehicleFactory::clone() {
    return new AquaticVehicleFactory(getHP(), getArea());
}