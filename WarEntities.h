#ifndef WARENTITIES_H
#define WARENTITIES_H

#include "Vehicles.h"
#include "Troops.h"
#include "Infrastructure.h"
#include "Citizens.h"
#include <vector>
/**
 * @brief THe WarEntities class holds all the vehicles, troops and infrastructure of a country
 *
 */
class WarEntities
{
private:
    /**
     * @brief A vector containing all the vehicles belonging to a country
     *
     */
    std::list<Vehicles *> vehicles;
    /**
     * @brief A vector containing all the troops belonging to a country
     *
     */
    std::list<Troops *> troops;
    /**
     * @brief A vector containing all the infrastructure belonging to a country
     *
     */
    std::list<Infrastructure *> infrastructure;

public:
    /**
     * @brief Construct a new War Entities object
     *
     */
    WarEntities();
    /**
     * @brief Create a copy of the passed in WarEntities object
     *
     * @param WarEnt THe WarEntities object to be copied
     */
    WarEntities(WarEntities &warEnt);
    /**
     * @brief Destroy the War Entities object
     *
     */
    ~WarEntities();
    /**
     * @brief Add a new vehicle to the vehicle vector
     *
     * @param theVehicle the vehicle to be added
     */
    void addVehicles(Vehicles *theVehicle);
    /**
     * @brief Add a new group of troops to the troops vector
     *
     * @param theTroops The group of troops to be added
     */
    void addTroops(Troops *theTroops);
    /**
     * @brief Add a new Infrastructure to the Infrastructure vector
     *
     * @param theInfrastructure The infrastructure to be added
     */
    void addInfrastructure(Infrastructure *theInfrastructure);
    /**
     * @brief Return the Vehicles vector
     *
     * @return std::vector<Vehicles*> The vehicles vector
     */
    std::list<Vehicles *> getVehicles();
    /**
     * @brief Return the Troops vector
     *
     * @return std::vector<Troops*> The troops vector
     */
    std::list<Troops *> getTroops();
    /**
     * @brief Return the Infrastructure vector
     *
     * @return std::vector<Infrastructure*> The infrastructure vector
     */
    std::list<Infrastructure *> getInfrastructure();
    /**
     * @brief return a clone of this object
     *
     * @return WarEntities The cloned object
     */
    WarEntities *clone();
    void removeInfrastructure(Infrastructure *);
    std::list<Citizens *> getFightingCitizens();
};
#endif