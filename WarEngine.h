#ifndef WARENGINE_H
#define WARENGINE_H
#include <vector>
#include "Country.h"
#include "Relationship.h"
#include "WarMap.h"
#include "WarPhase.h"
#include "Infrastructure.h"
#include "TroopType.h"
#include "Troops.h"
#include "Vehicles.h"
using namespace std;

class Memento;
class WarEngine {
private:
    WarMap *map;
    Communication *communication;
    list<Country *> allCountries;
    list<Relationship *> allRelationships;

    Country *getCountry(string countryName);
    Relationship *getRelationship(string relationshipName);
    Country *getCountryFromArea(string areaName);
    Area *getArea(string areaName);
    list<Infrastructure *> getInfrastructureInArea(Area* area, typeOfInfrastructure type);
    list<Infrastructure *> getAllInfrastructureInArea(Area* area);
    list<Infrastructure *> getAllFacilitiesInArea(Area* area);
    list<Troops *> getTroopsInArea(Area* area, Country* country);
    list<Vehicles *> getVehiclesInArea(Area* area, Country* country);
    double getTravelDistance(Vehicles *vehicle, Area* destination);
    double getTravelDistance(Troops *troops, Area* destination);
    list<Area *> getTravelPath(Vehicles *vehicle, Area* destination);
    list<Area *> getTravelPath(Troops *troops, Area* destination);
    void moveTroops(Area* area, Country* country, int maxDistance);
    void moveVehicles(Area* area, Country* country, int maxDistance);

public:
    WarEngine();
    ~WarEngine();
    void newWarPhase();
    void reverseWarPhase();
    void addCountry(string name, int numCitizens);
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
    void printCountryStatus(string countryName);
    void distributeTroopsAndVehicles(string countryName);
    bool countryStillExists(string countryName);

    void run(string Mode);
    Memento *createMemento();
    list<Country *> getCountryGroup();
    void setCountryGroup(list<Country *> newCountryGroup);
    void removeAreaAt(int index);
    void reinstateMemento(Memento *memento);
    void setWarMap(WarMap *newMap);
};

#endif