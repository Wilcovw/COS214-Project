#ifndef FACTORY_AND_OBSERVER_AIRCRAFT_H
#define FACTORY_AND_OBSERVER_AIRCRAFT_H

#include <string>
#include "Vehicles.h"
#include "ResearchAndDevelopmentCentre.h"

using namespace std;
class Aircraft : public Vehicles
{
public:
    /**
     * @brief Constructor for Aircraft class
     * @param location
     * @param hp
     * @param damage
     * @param speed
     */
    Aircraft(Area *location, double hp, double damage, double speed);
    virtual ~Aircraft();
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
     * @brief Clones the current Vechile Object
     *
     * @return Vehicles*
     */
    Vehicles *clone();
};

#endif // FACTORY_AND_OBSERVER_AIRCRAFT_H
