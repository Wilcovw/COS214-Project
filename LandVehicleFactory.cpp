//
// Created by wilco on 2022/10/16.
//

#include "LandVehicleFactory.h"

Vehicles *LandVehicleFactory::createVehicle(string model, double HP, double damage, double speed) {
    Vehicles *v = new LandVehicles(model, HP, damage, speed);
    setVehicle(v);
    return v;
}