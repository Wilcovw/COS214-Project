//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "Aircraft.h"

class AircraftDevelopment : public ResearchAndDevelopmentCentre{
public:
    void startDeveloping(Aircraft *v);

};


#endif //FACTORY_AND_OBSERVER_AIRCRAFTDEVELOPMENT_H
