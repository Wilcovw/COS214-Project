#ifndef WARENGINE_H
#define WARENGINE_H
#include <vector>
#include "Country.h"
#include "WarMap.h"
#include "WarPhase.h"
#include "Infrastructure.h"
using namespace std;

class Memento;
class WarEngine
{
private:
    WarMap* map;
    Communication* communication;
	vector<Country*> allCountries;
public:
    WarEngine();
    void addCountry(string name, int numCitizens);
    Country* getCountry(string countryName);
    Country* getCountryFromArea(string areaName);
    void addArea(string areaName, string countryName);
    Area* getArea(string areaName);
    void addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance);
    void addInfrastructure(typeOfInfrastructure type, string areaName);
    vector<Infrastructure*> getInfrastructureInArea(string areaName, typeOfInfrastructure type);
    void run(string Mode);
    Memento* createMemento();
    Country pickCountry();
    vector<Country*> getCountryGroup();
    void setCountryGroup(vector<Country*> newCountryGroup);
    void removeCountryAt(int index);
    void removeAreaAt(int index);
    void reinstateMemento(Memento *memento);
    void setWarMap(WarMap* newMap);
};

#endif