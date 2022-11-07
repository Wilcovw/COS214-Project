#ifndef WARPHASE_H
#define WARPHASE_H
#include <list>
#include <string>
using namespace std;

enum typeOfInfrastructure : int
{
    iRoad,
    iHarbour,
    iRunway,
    iLandDevelopment,
    iAquaticDevelopment,
    iAircraftDevelopment,
    iLandFactory,
    iAquaticFactory,
    iAircraftFactory,
    iGroundCamp,
    iNavyCamp,
    iAirforceCamp
};

enum vehicleType : int
{
    landVehicle,
    aquaticVehicle,
    aircraftVehicle
};

enum theTroopTypes : int
{
    theGenerals,
    theSoldiers,
    theSpecialForces
};

enum kindOfTroops : int
{
    tGroundTroops,
    tNavy,
    tAirforce
};

class WarMap;
class Country;
class Communication;
class CommunicationBroadcast;
class Relationship;
class Infrastructure;
class Troops;
class Vehicles;
class Area;
class Memento;
class WarPhase
{
private:
    /**
     * @brief WarMap dtores all Areas involved in war
     *
     */
    WarMap *map;
    /**
     * @brief Stores communication object that works as mediator
     *
     */
    Communication *communication;
    /**
     * @brief Stores list of all countries involved in the war
     *
     */
    list<Country *> allCountries;
    /**
     * @brief Stores all the relationship classes that function as the composite class
     *
     */
    list<Relationship *> allRelationships;
    /**
     * @brief s a list of all countries cloned
     *
     * @param head The head of the composite class
     * @return list<Country *>
     */
    list<Country *> cloneCountries(Relationship *head);
    /**
     * @brief  Returns a list of all relationships cloned
     *
     * @param head The head of the composite class
     * @return list<Relationship *>
     */
    list<Relationship *> cloneRelationship(Relationship *head);
    /**
     * @brief  Returns a country object with the name passed in as parameter
     *
     * @param countyName The name of the country to return
     * @return Country*
     */
    Country *getCountry(string countryName);
    /**
     * @brief  Returns a realtionship object with the name passed in as parameter
     *
     * @param relationshipName The name of the relationship to return
     * @return Realtionship*
     */
    Relationship *getRelationship(string relationshipName);
    /**
     * @brief  Returns a realtionship object with the name passed in as parameter
     *
     * @param relationshipName The name of the relationship to return
     * @return Realtionship*
     */
    Country *getCountryFromArea(string areaName);
    /**
     *  @brief  Returns an Area object with the name passed in as parameter
     *
     * @param areaName The name of the relationship to return
     * @return Area**
     */
    Area *getArea(string areaName);
    /**
     * @brief  Returns list of all infrastructure in the Area of a certain type
     *
     * @param area The name of the area to search in
     * @param type The name of the type of infrastructure to return
     * @return list<Infrastructure*>
     */
    list<Infrastructure *> getInfrastructureInArea(Area *area, typeOfInfrastructure type);
    /**
     * @brief  Returns list of all infrastructure in the Area
     *
     * @param area The name of the area to search in
     * @return list<Infrastructure*>
     */
    list<Infrastructure *> getAllInfrastructureInArea(Area *area);
    /**
     * @brief  Returns list of all facility infrastructure in the Area
     *
     * @param area The name of the area to search in
     * @return list<Infrastructure*>
     */
    list<Infrastructure *> getAllFacilitiesInArea(Area *area);
    /**
     * @brief  Returns list of all troops fom a certain country in the Area
     *
     * @param area The name of the area to search in
     * @param country The name of the country's troops you are looking for
     * @return list<Troops*>
     */
    list<Troops *> getTroopsInArea(Area *area, Country *country);
    /**
     * @brief  Returns list of all vehicles fom a certain country in the Area
     *
     * @param area The name of the area to search in
     * @param country The name of the country's troops you are looking for
     * @return list<Vehicles*>
     */
    list<Vehicles *> getVehiclesInArea(Area *area, Country *country);
    /**
     * @brief  Returns travel distance to certain Area
     *
     * @param destination The name of the area to travel to
     * @param vehicle The vehicles that have to travel
     * @return double
     */
    double getTravelDistance(Vehicles *vehicle, Area *destination);
    /**
     * @brief  Returns travel distance to certain Area
     *
     * @param destination The name of the area to travel to
     * @param troops The troops that have to travel
     * @return double
     */
    double getTravelDistance(Troops *troops, Area *destination);
    /**
     * @brief  Returns list of areas to travel through to get to certain Area
     *
     * @param destination The name of the area to travel to
     * @param vehicle The vehicles that have to travel
     * @return list<Area *>
     */
    list<Area *> getTravelPath(Vehicles *vehicle, Area *destination);
    /**
     * @brief  Returns list of areas to travel through to get to certain Area
     *
     * @param destination The name of the area to travel to
     * @param troops The troops that have to travel
     * @return list<Area *>
     */
    list<Area *> getTravelPath(Troops *troops, Area *destination);
    /**
     * @brief  Moves the troops to a certain area but is limited by a max distance
     *
     * @param area Area to move to
     * @param country Country's troops that have to move
     * @param maxDistance The max distance that the troops can move
     */
    void moveTroops(Area *area, Country *country, int maxDistance);
    /**
     * @brief  Moves the vehicles to a certain area but is limited by a max distance
     *
     * @param area Area to move to
     * @param country Country's vehicles that have to move
     * @param maxDistance The max distance that the vehicles can move
     */
    void moveVehicles(Area *area, Country *country, int maxDistance);

public:
    /**
     * @brief Construct a new War Phase object
     *
     */
    WarPhase();
    /**
     * @brief Destroy the War Phase object
     *
     */
    ~WarPhase();
    /**
     * @brief return a clone of the current state of the WWarPhase object
     *
     * @return WarPhase*
     */
    WarPhase *clone();
    /**
     * @brief Create a new Memento, to store the current Warphase
     *
     */
    Memento *newWarPhase();
    /**
     * @brief Restores the old war phase
     *
     */
    void reverseWarPhase(Memento *memento);
    /**
     * @brief Adds a new Country to the Map
     *
     * @param name Name of the Country
     * @param numCitizens Number of citizen of the Country
     */
    void addCountry(string name, int numCitizens);
    /**
     * @brief Creates a relationship
     *
     * @param relationshipName
     */
    void addRelationship(string relationshipName);
    /**
     * @brief Adds a country to a relationship
     *
     * @param countryNamString Nane of country to add to realtionship
     * @param relationshipName Name of the relationship to be added to
     */
    void addCountrytoRelationship(string countryNamestring, string relationshipName);
    /**
     * @brief Adds a relationship to a relationship
     *
     * @param relationshipNameParent Nane of parent relationship to add to
     * @param relationshipNameChild Name of the child relationship to be added
     */
    void addRelationshipToRelationship(string relationshipNameParent, string relationshipNameChild);
    /**
     * @brief Adds an area to a country
     *
     * @param areaName Name of area to add
     * @param countryName Name of the country to add to
     */
    void addArea(string areaName, string countryName);
    /**
     * @brief Adds a connection between infrasctructures
     *
     * @param type The type of infratstructures to add the connection
     * @param sourceName Destination of the connection
     * @param destinationName Source of the connection
     * @param distance The length of the connection
     */
    void addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance);
    /**
     * @brief Adds infrastructure to area
     *
     * @param type Type of infrastructure to add
     * @param areaName Name of area to add to
     */
    void addInfrastructure(typeOfInfrastructure type, string areaName);
    /**
     * @brief Adds troops to area
     *
     * @param areaName Name of area to add to
     * @param kind Kind of troops to add
     * @param type Type of troops to add
     */
    void addTroops(string areaName, kindOfTroops kind, theTroopTypes type);
    /**
     * @brief Adds vehicles to area
     *
     * @param areaName Name of area to add to
     * @param vehicleType Type of vehicle to add
     */
    void addVehicles(string areaName, vehicleType vehicleType);
    /**
     * @brief Tells country to attack an area and returns whether it was successful
     *
     * @param areaName Name of area to attack
     * @param countryName Country that attacks
     * @return bool
     */
    bool attackArea(string areaName, string countryName);
    /**
     * @brief Move troops to area
     *
     * @param areaName Name of area to move to
     * @param countryName Country's troops that should move
     */
    void moveTroops(string areaName, string countryName);
    /**
     * @brief Move troops to area
     *
     * @param areaName Name of area to move to
     * @param countryName Country's troops that should move
     */
    void moveVehicles(string areaName, string countryName);
    /**
     * @brief Print status of the country
     *
     * @param countryName Country's status to print
     * @param displayInfrastructure Says wheter to display the infrastructure's status or not
     */
    void printCountryStatus(string countryName, bool displayInfrastructure);
    /**
     * @brief Print status of the area
     *
     * @param areaName Area's status to print
     * @param displayInfrastructure Says wheter to display the infrastructure's status or not
     */
    void printAreaStatus(string areaName, bool displayInfrastructure);
    /**
     * @brief Distribute's troops and vehicles of a country
     *
     * @param countryName Country's troops and vehicles to distribute
     */
    void distributeTroopsAndVehicles(string countryName);
    /**
     * @brief Checks if a country still exist
     *
     * @param countryName The country's existence that should be checked
     * @return bool
     */
    bool countryStillExists(string countryName);
    /**
     * @brief Upgrades a type of vehicles in an area
     *
     * @param type Type of vehicles to upgrade
     * @param areaName Area to upgrade vehicles in
     */
    void upgradeVehiclesInArea(vehicleType type, string areaName);
    /**
     * @brief Returns list of all areas that a country can attack
     *
     * @param defendingCountryName Country that will defend the attack
     * @param attackingCountryName Country that wants to attack
     * @return list<string>
     */
    list<string> getAttackableAreasInCountry(string defendingCountryName, string attackingCountryName);
    /**
     * @brief Makes citizens revolt
     *
     * @param countryName Country's citizens that will revolt
     */
    void revolt(string countryName);
    /**
     * @brief Returns list of all enemies of a country
     *
     * @param countryName Country that will defend the attack
     * @return list<string>
     */
    list<string> getCountryEnemies(string countryName);
    /**
     * @brief Call the mediator pattern on a country to send a message to a country or relationship
     *
     * @param messageReceiver
     * @param messageSender
     * @param message
     */
    void sendBroadcast(string messageReceiver, string messageSender, string message);
};

#endif