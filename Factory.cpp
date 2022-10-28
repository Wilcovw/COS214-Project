//
// Created by wilco on 2022/10/16.
//


#include "Factory.h"

void Factory::setVehicle(Vehicles *v) {
    vehicle=v;
}

Vehicles *Factory::getVehicle() {
    return vehicle;
}

//TODO: make virtual and expand to child classes
void Factory::destroy() {
//    ~Factory();
}
