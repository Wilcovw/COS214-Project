#ifndef WARENTITIES_H
#define WARENTITIES_H

#include "Vehicles.h"
#include "Troops.h"
#include "Infrastructure.h"
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
    std::vector<Vehicles *> vehicles;
    /**
     * @brief A vector containing all the troops belonging to a country
     *
     */
    std::vector<Troops *> troops;
    /**
     * @brief A vector containing all the infrastructure belonging to a country
     *
     */
    std::vector<Infrastructure *> infrastructure;

public:
    /**
     * @brief Construct a new War Entities object
     *
     */
    WarEntities();
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
    std::vector<Vehicles *> getVehicles();
    /**
     * @brief Return the Troops vector
     *
     * @return std::vector<Troops*> The troops vector
     */
    std::vector<Troops *> getTroops();
    /**
     * @brief Return the Infrastructure vector
     *
     * @return std::vector<Infrastructure*> The infrastructure vector
     */
    std::vector<Infrastructure *> getInfrastructure();
};
#endif