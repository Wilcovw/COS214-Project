#ifndef FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H
#define FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H

#include "Factory.h"
#include "Aircraft.h"

class AircraftFactory : public Factory
{
public:
    /**
     * @brief constructor
     */
    AircraftFactory(double hp, Area *area) : Factory(hp, area){};
    /**
     * @brief virtual destructor
     */
    virtual ~AircraftFactory() {}
    /**
     * @brief creates a vehicle with passed in parameters as values and returns that vehicle
     * @param model
     * @param HP
     * @param damage
     * @param speed
     * @return vehicle with passed in parameters
     */
    Vehicles *createVehicle(string model, double HP, double damage, double speed);
    /**
     * @brief Calls class destructor
     */
    void destroy();
};

#endif // FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H
