#ifndef WARENTITIES_H
#define WARENTITIES_H

#include "Vehicles.h"
#include "Troops.h"
#include "Infrastructure.h"
#include "Citizens.h"
#include <list>
/**
 * @brief THe WarEntities class holds all the vehicles, troops and infrastructure of a country
 *
 */
class WarEntities
{
private:
    /**
     * @brief A list containing all the vehicles belonging to a country
     *
     */
    std::list<Vehicles *> vehicles;
    /**
     * @brief A list containing all the troops belonging to a country
     *
     */
    std::list<Troops *> troops;
    /**
     * @brief A list containing all the infrastructure belonging to a country
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
     * @brief Add a new vehicle to the vehicle list
     *
     * @param theVehicle the vehicle to be added
     */
    void addVehicles(Vehicles *theVehicle);
    /**
     * @brief Add a new group of troops to the troops list
     *
     * @param theTroops The group of troops to be added
     */
    void addTroops(Troops *theTroops);
    /**
     * @brief Add a new Infrastructure to the Infrastructure list
     *
     * @param theInfrastructure The infrastructure to be added
     */
    void addInfrastructure(Infrastructure *theInfrastructure);
    /**
     * @brief Return the Vehicles list
     *
     * @return std::list<Vehicles*> The vehicles list
     */
    std::list<Vehicles *> getVehicles();
    /**
     * @brief Return the Troops list
     *
     * @return std::list<Troops*> The troops list
     */
    std::list<Troops *> getTroops();
    /**
     * @brief Return the Infrastructure list
     *
     * @return std::list<Infrastructure*> The infrastructure list
     */
    std::list<Infrastructure *> getInfrastructure();
    /**
     * @brief return a clone of this object
     *
     * @return WarEntities The cloned object
     */
    WarEntities *clone();
    /**
     * @brief removes theObject from infrastructure
     * @param theObject
     */
    void removeInfrastructure(Infrastructure *);
    /**
     * @brief removes theTroop from troops
     * @param theTroop
     */
    void removeTroops(Troops *);
    /**
     * @brief removes theVehicle from vehicles
     * @param theVehicle
     */
    void removeVehicles(Vehicles *);
    /**
     * @brief returns a list of Citizens who are currently fighting in war
     * @return list<Citizens *> - a list of fighting citizens
     */
    std::list<Citizens *> getFightingCitizens();
};
#endif