//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AIRCRAFT_H
#define FACTORY_AND_OBSERVER_AIRCRAFT_H

#include <string>
#include "Vehicles.h"

using namespace std;
class Aircraft : public Vehicles{
public:
    Aircraft(string model, double hp, double damage, double speed);
};


#endif //FACTORY_AND_OBSERVER_AIRCRAFT_H
