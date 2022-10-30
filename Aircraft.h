//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AIRCRAFT_H
#define FACTORY_AND_OBSERVER_AIRCRAFT_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
class Aircraft : public Vehicles{
public:
    /**
     * @brief Constructor for Aircraft class
     * @param model
     * @param hp
     * @param damage
     * @param speed
     */
    Aircraft(string model, double hp, double damage, double speed);
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


#endif //FACTORY_AND_OBSERVER_AIRCRAFT_H
