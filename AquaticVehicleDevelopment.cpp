#include "AquaticVehicleDevelopment.h"

void AquaticVehicleDevelopment::destroy() {
    delete this;
}

Infrastructure *AquaticVehicleDevelopment::clone() {
    return new AquaticVehicleDevelopment(HP, location);
}