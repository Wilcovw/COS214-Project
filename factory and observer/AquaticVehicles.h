//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLES_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
class AquaticVehicles : public Vehicles {
public:
    /**
     * @brief Constructor fot AquaticVehicles class
     * @param model
     * @param hp
     * @param damage
     * @param speed
     */
    AquaticVehicles(string model, double hp, double damage, double speed);
    /**
     * @brief method that calls the vehicle's increments level method
     */
    void update();
    /**
     * @brief adds to ResearchAndDevelopmentCentre list, which stores items to be upgraded
     * @param r
     */
    void readyToUpgrade(ResearchAndDevelopmentCentre *r);
};


#endif //FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
