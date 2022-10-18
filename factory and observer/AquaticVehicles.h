//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLES_H

#include <string>
#include "Vehicles.h"

using namespace std;
class AquaticVehicles : public Vehicles {
public:
    AquaticVehicles(string model, double hp, double damage, double speed);

};


#endif //FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
