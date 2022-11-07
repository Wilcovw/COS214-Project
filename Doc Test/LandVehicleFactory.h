#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H

#include "Factory.h"
#include "LandVehicles.h"

class LandVehicleFactory : public Factory
{
public:
    /**
     * @brief constructor
     */
    LandVehicleFactory(double hp, Area *area);
    /**
     * @brief virtual destructor
     */
    virtual ~LandVehicleFactory(){};
    /**
     * @brief creates a vehicle with passed in parameters as values and returns that vehicle
     * @param HP
     * @param damage
     * @param speed
     * @return vehicle with passed in parameters
     */
    Vehicles *createVehicle(double HP, double damage, double speed);
    /**
     * @brief Calls class destructor
     */
    virtual void destroy();
    /**
     * @brief Makes a copy of the current Factory
     *
     * @return Infrastructure*
     */
    virtual Infrastructure *clone(Area *newArea);
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
