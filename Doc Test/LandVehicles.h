#ifndef FACTORY_AND_OBSERVER_LANDVEHICLES_H
#define FACTORY_AND_OBSERVER_LANDVEHICLES_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
/**
 * @brief LandVehicles are all vehicles that can only travel on land. It is the child class of Vehicles
 */
class LandVehicles : public Vehicles
{
public:
    /**
     * @brief Constructor for LandVehicles class
     * @param hp
     * @param damage
     * @param speed
     */
    LandVehicles(Area *location, double hp, double damage, double speed);
	/**
	 * @brief Destroy the Land Vehicles object
	 * 
	 */
    ~LandVehicles();
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
     * @brief Makes a copy of the current Vechile
     *
     * @return Vehicles*
     */
    Vehicles *clone();
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLES_H
