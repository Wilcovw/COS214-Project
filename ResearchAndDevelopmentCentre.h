#ifndef FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
#define FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H

#include <vector>
#include "Infrastructure.h"
#include "Vehicles.h"

class ResearchAndDevelopmentCentre : public Infrastructure
{
protected:
    vector<Vehicles *> vehicleToBeUpgraded;

public:
    ResearchAndDevelopmentCentre(double hp, Area *area) : Infrastructure(hp, area){};
    /**
     * @brief starts the developing of upgrades for vehicles
     */
    void startDeveloping();
    /**
     * @brief stops the development of upgrades for vehicles
     */
    void stopDeveloping();
    /**
     * @brief Notifies the vehicles in  the list that their upgrade() functions have to be called
     */
    void notifyDevelop();
    /**
     * @brief Destructor for the class
     */
    void destroy();
    /**
     * @brief prints vehicleToBeUpgraded vector
     */
    void printList();
    /**
     * @brief adds v to vehicleToBeUpgraded vector
     * @param v
     */
    void addToList(Vehicles *v);
};

#endif // FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
