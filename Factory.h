#ifndef FACTORY_AND_OBSERVER_FACTORY_H
#define FACTORY_AND_OBSERVER_FACTORY_H

#include "Infrastructure.h"
#include "Vehicles.h"

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
    virtual Vehicles *createVehicle(string model, double HP, double damage, double speed) = 0;
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
    void destroy();
};

#endif // FACTORY_AND_OBSERVER_FACTORY_H
