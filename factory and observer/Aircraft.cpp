//
// Created by wilco on 2022/10/16.
//

#include "Aircraft.h"

Aircraft::Aircraft(string model, double hp, double damage, double speed) : Vehicles(model, hp, damage, speed) {
    type = "Aircraft";
}
