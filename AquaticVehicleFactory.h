//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H

#include "Factory.h"
#include "AquaticVehicles.h"

class AquaticVehicleFactory : public Factory{
public:
    AquaticVehicleFactory() {};
    virtual ~AquaticVehicleFactory() {};
    Vehicles* createVehicle(string model, double HP, double damage, double speed);

};


#endif //FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H
