#ifndef FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
#define FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H

#include <vector>
#include "Infrastructure.h"
#include "Vehicles.h"

/**
 * @brief ResearchAndDevelopmentCentre takes the role of the Observer Class in the Observer design pattern. It inherits from Inrastructure
 */
class ResearchAndDevelopmentCentre : public Infrastructure
{
protected:
    /**
     * a vector of vehicles that need to be upgraded.
     */
    vector<Vehicles *> vehicleToBeUpgraded;

public:
	/**
	 * @brief Construct a new Research And Development Centre object
	 * 
	 * @param hp The health of the Center
	 * @param area The Area the Centre is located
	 */
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
     * @brief calls destructor for the class
     */
    virtual void destroy();
    /**
     * @brief prints vehicleToBeUpgraded vector
     */
    void printList();
    /**
     * @brief adds v to vehicleToBeUpgraded vector
     * @param v - a Vehicle to be added to the list
     */
    void addToList(Vehicles *v);
    /**
     * @brief returns a clone of the current class
     * @return Infrastructure* - a clone of the current class is returned
     */
    virtual Infrastructure *clone(Area *newArea);
};

#endif // FACTORY_AND_OBSERVER_RESEARCHANDDEVELOPMENTCENTRE_H
