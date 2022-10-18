//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
#define FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H

#include "ResearchAndDevelopmentCentre.h"
#include "AquaticVehicles.h"

class AquaticVehicleDevelopment : ResearchAndDevelopmentCentre {
public:
    void startDeveloping(AquaticVehicles *v);


};


#endif //FACTORY_AND_OBSERVER_AQUATICVEHICLEDEVELOPMENT_H
