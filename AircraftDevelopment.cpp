#include "AircraftDevelopment.h"

void AircraftDevelopment::destroy() {
    delete this;
}

Infrastructure *AircraftDevelopment::clone() {
    return new AircraftDevelopment(HP, location);
}

