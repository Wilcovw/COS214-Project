#ifndef WARENGINE_H
#define WARENGINE_H
#include <vector>
#include "Country.h"
#include "WarMap.h"
#include "WarPhase.h"
#include "Infrastructure.h"
#include "TroopType.h"
#include "Troops.h"
#include "Vehicles.h"
using namespace std;

class Memento;
class WarEngine
{
private:
    WarMap *map;
    Communication *communication;
    vector<Country *> allCountries;
    Country *getCountry(string countryName);
    Country *getCountryFromArea(string areaName);
    Area *getArea(string areaName);
    list<Infrastructure*> getInfrastructureInArea(string areaName, typeOfInfrastructure type);
    list<Troops*> getTroopsInArea(string areaName, string countryName);
    list<Vehicles*> getVehiclesInArea(string areaName, string countryName);
    double getTravelDistance(Vehicles* vehicle, string areaName);
    double getTravelDistance(Troops* troops, string areaName);
    list<Area*> getTravelPath(Vehicles* vehicle, string areaName);
    list<Area*> getTravelPath(Troops* troops, string areaName);

public:
    WarEngine();
    ~WarEngine();
    void addCountry(string name, int numCitizens);
    void addArea(string areaName, string countryName);
    void addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance);
    void addInfrastructure(typeOfInfrastructure type, string areaName);
    void addTroops(string areaName, kindOfTroops kind, theTroopTypes type);
    void addVehicles(string areaName, vehicleType vehicleType);
    void attackArea(string areaName, string countryName);
    void moveTroops(string areaName, string countryName);
    void moveVehicles(string areaName, string countryName);

    void run(string Mode);
    Memento *createMemento();
    Country pickCountry();
    vector<Country *> getCountryGroup();
    void setCountryGroup(vector<Country *> newCountryGroup);
    void removeCountryAt(int index);
    void removeAreaAt(int index);
    void reinstateMemento(Memento *memento);
    void setWarMap(WarMap *newMap);
};

#endif