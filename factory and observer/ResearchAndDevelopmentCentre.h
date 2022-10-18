//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
#define FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H

#include "Infrastructure.h"
#include "Vehicles.h"

class ResearchAndDevelopmentCentre : public Infrastructure {
protected:
    Vehicles *vehicleToBeUpgraded;
public:
    void destroy();

};


#endif //FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
