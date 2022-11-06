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
    WarMap *map;
    Communication *communication;
    list<Country *> allCountries;
    list<Relationship *> allRelationships;
    list<Country *> cloneCountries(Relationship *head);
    list<Relationship *> cloneRelationship(Relationship *head);
    Country *getCountry(string countryName);
    Relationship *getRelationship(string relationshipName);
    Country *getCountryFromArea(string areaName);
    Area *getArea(string areaName);
    list<Infrastructure *> getInfrastructureInArea(Area *area, typeOfInfrastructure type);
    list<Infrastructure *> getAllInfrastructureInArea(Area *area);
    list<Infrastructure *> getAllFacilitiesInArea(Area *area);
    list<Troops *> getTroopsInArea(Area *area, Country *country);
    list<Vehicles *> getVehiclesInArea(Area *area, Country *country);
    double getTravelDistance(Vehicles *vehicle, Area *destination);
    double getTravelDistance(Troops *troops, Area *destination);
    list<Area *> getTravelPath(Vehicles *vehicle, Area *destination);
    list<Area *> getTravelPath(Troops *troops, Area *destination);
    void moveTroops(Area *area, Country *country, int maxDistance);
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
    void addCountrytoRelationship(string countryNamestring, string relationshipName);
    void addRelationshipToRelationship(string relationshipNameParent, string relationshipNameChild);
    void addArea(string areaName, string countryName);
    void addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance);
    void addInfrastructure(typeOfInfrastructure type, string areaName);
    void addTroops(string areaName, kindOfTroops kind, theTroopTypes type);
    void addVehicles(string areaName, vehicleType vehicleType);
    void attackArea(string areaName, string countryName);
    void moveTroops(string areaName, string countryName);
    void moveVehicles(string areaName, string countryName);
    void printCountryStatus(string countryName, bool displayInfrastructure);
    void printAreaStatus(string areaName);
    void distributeTroopsAndVehicles(string countryName);
    bool countryStillExists(string countryName);
    void upgradeVehiclesInArea(vehicleType type, string areaName);
    list<string> getAreasInRelationship(string relationship);
    void revolt(string countryName);

    /*Memento *createMemento();
    list<Country *> getCountryGroup();
    void setCountryGroup(list<Country *> newCountryGroup);
    void removeAreaAt(int index);
    void reinstateMemento(Memento *memento);
    void setWarMap(WarMap *newMap);*/
};

#endif