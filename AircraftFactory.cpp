#include "AircraftFactory.h"

Vehicles *AircraftFactory::createVehicle(string model, Area* location, double HP, double damage, double speed) {
    Vehicles *v = new Aircraft(model, location, HP, damage, speed);
    setVehicle(v);
    return v;
}

void AircraftFactory::destroy() {
    delete this;
}

Infrastructure *AircraftFactory::clone() {
    return new AircraftFactory(getHP(), getArea());
}