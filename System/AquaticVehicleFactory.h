#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H

#include "Factory.h"
#include "AquaticVehicles.h"
/**
 * @brief AquaticVehicleFactory inherits from factory and is used to create navy vehicles
 *
 */
class AquaticVehicleFactory : public Factory
{
public:
    /**
     * @brief constructor
     */
    AquaticVehicleFactory(double hp, Area *area);
    /**
     * @brief virtual destructor
     */
    virtual ~AquaticVehicleFactory(){};
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

#endif // FACTORY_AND_OBSERVER_AQUATICVEHICLEFACTORY_H
