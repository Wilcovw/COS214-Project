//
// Created by wilco on 2022/10/16.
//

#include "AquaticVehicles.h"

AquaticVehicles::AquaticVehicles(string model, double hp, double damage, double speed) : Vehicles(model, hp, damage,speed) {
    type = "Aquatic Vehicle";
}
