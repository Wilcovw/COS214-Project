//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H

#include "Factory.h"
#include "LandVehicles.h"

class LandVehicleFactory : public Factory {
public:
    Vehicles* createVehicle(string model, double HP, double damage, double speed);

};


#endif //FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
