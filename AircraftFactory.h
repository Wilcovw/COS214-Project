//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H
#define FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H

#include "Factory.h"
#include "Aircraft.h"

class AircraftFactory : public Factory{
public:
    AircraftFactory() {};
    virtual ~AircraftFactory(){}

    Vehicles* createVehicle(string model, double HP, double damage, double speed);

};


#endif //FACTORY_AND_OBSERVER_AIRCRAFTFACTORY_H
