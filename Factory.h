//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_FACTORY_H
#define FACTORY_AND_OBSERVER_FACTORY_H

#include "Infrastructure.h"
#include "Vehicles.h"

class Factory : public Infrastructure{
private:
    Vehicles* vehicle;

public:
    Factory() {};
    virtual ~Factory() {};

    /**
     * @param model
     * @param HP
     * @param damage
     * @param speed
     * @return
     * Vehicle is returned with parameters given as attributes
     */
    virtual Vehicles* createVehicle(string model, double HP, double damage, double speed) = 0;
    void setVehicle(Vehicles *v);
    Vehicles *getVehicle();
    void destroy();
};


#endif //FACTORY_AND_OBSERVER_FACTORY_H
