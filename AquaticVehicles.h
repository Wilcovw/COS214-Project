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
     * @param hp
     * @param damage
     * @param speed
     */
    AquaticVehicles(Area* location, double hp, double damage, double speed);
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
    virtual ~AquaticVehicles();
	/**
	 * @brief Makes a copy of the Current Vehicle
	 * 
	 * @return Vehicles* 
	 */
    Vehicles* clone();
};

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLES_H
