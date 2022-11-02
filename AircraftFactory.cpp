#include "AircraftFactory.h"

<<<<<<< Updated upstream
Vehicles *AircraftFactory::createVehicle(string model, Area* location, double HP, double damage, double speed) {
    Vehicles *v = new Aircraft(model, location, HP, damage, speed);
=======
AircraftFactory::AircraftFactory(double hp, Area *area) : Factory(hp, area) {
    type = ::iAircraftFactory;
}

Vehicles *AircraftFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new Aircraft(model, HP, damage, speed);
>>>>>>> Stashed changes
    setVehicle(v);
    return v;
}

void AircraftFactory::destroy() {
    delete this;
}

Infrastructure *AircraftFactory::clone() {
    return new AircraftFactory(getHP(), getArea());
}