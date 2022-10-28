//
// Created by wilco on 2022/10/16.
//

#include "AircraftFactory.h"

Vehicles *AircraftFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new Aircraft(model, HP, damage, speed);
    setVehicle(v);
    return v;
}


