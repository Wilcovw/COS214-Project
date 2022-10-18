//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "LandVehicles.h"

class LandVehicleDevelopment : ResearchAndDevelopmentCentre {
public:
    void startDeveloping(LandVehicles *v);

};


#endif //FACTORY_AND_OBSERVER_LANDVEHICLEDEVELOPMENT_H
