#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLES_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
class AquaticVehicles : public Vehicles
{
public:
    /**
     * @brief Constructor for AquaticVehicles class
     * @param model
     * @param hp
     * @param damage
     * @param speed
     */
    AquaticVehicles(string model, Area* location, double hp, double damage, double speed);
    /**
     * @brief method that calls the vehicle's increments level method
     */
    void update();
    /**
     * @brief adds to ResearchAndDevelopmentCentre list, which stores items to be upgraded
     * @param r
     */
    void readyToUpgrade(ResearchAndDevelopmentCentre *r);
    /**
    * @brief calls class destructor
    */
    void destroy();
    Vehicles* clone();
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
