//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
#define FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H

#include <vector>
#include "Infrastructure.h"
#include "Vehicles.h"

class ResearchAndDevelopmentCentre : public Infrastructure {
protected:
    vector<Vehicles*> vehicleToBeUpgraded;
public:
    //developing per vehicle
    void startDeveloping();
    void stopDeveloping();
    void notifyDevelop();
    void destroy();
    void printList();
    void addToList(Vehicles *v);

};


#endif //FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
