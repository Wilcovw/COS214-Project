#ifndef FACTORY_AND_OBSERVER_FACTORY_H
#define FACTORY_AND_OBSERVER_FACTORY_H

#include "Infrastructure.h"
#include "Vehicles.h"
/**
 * @brief Factory inherits from infrastructure and is used to create vehicles
 *
 */
class Factory : public Infrastructure
{
private:
    Vehicles *vehicle;

public:
    Factory(double hp, Area *area) : Infrastructure(hp, area){};
    virtual ~Factory(){};

    /**
     * @brief Creates Vehicle
     * @param model
     * @param HP
     * @param damage
     * @param speed
     * @return a single vehicle is returned, with parameters given as attributes
     */
    virtual Vehicles *createVehicle(Area *location, double HP, double damage, double speed);
    /**
     * @brief sets the private variable of this class to passed in parameter
     * @param v
     */
    void setVehicle(Vehicles *v);
    /**
     * @brief returns the private variable of this class.
     * @return vehicle
     */
    Vehicles *getVehicle();
    /**
     * @brief destructor
     */
    virtual void destroy();
    /**
     * @brief Makes a copy of the current Factory
     *
     * @return Infrastructure*
     */
    virtual Infrastructure *clone(Area *newArea);
};

#endif // FACTORY_AND_OBSERVER_FACTORY_H