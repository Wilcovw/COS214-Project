#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H

#include "Factory.h"
#include "LandVehicles.h"

class LandVehicleFactory : public Factory
{
public:
    /**
     * @brief default constructor
     */
    LandVehicleFactory(){};
    /**
     * @brief virtual destructor
     */
    virtual ~LandVehicleFactory(){};
    /**
     * @brief creates a vehicle with passed in parameters as values and returns that vehicle
     * @param model
     * @param HP
     * @param damage
     * @param speed
     * @return vehicle with passed in parameters
     */
    Vehicles *createVehicle(string model, double HP, double damage, double speed);
};

#endif // FACTORY_AND_OBSERVER_LANDVEHICLEFACTORY_H
