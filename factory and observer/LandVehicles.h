//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_LANDVEHICLES_H
#define FACTORY_AND_OBSERVER_LANDVEHICLES_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
class LandVehicles : public Vehicles {
public:
    LandVehicles(string model, double hp, double damage, double speed);
    void update();
    void readyToUpgrade(ResearchAndDevelopmentCentre *r);
};


#endif //FACTORY_AND_OBSERVER_LANDVEHICLES_H
