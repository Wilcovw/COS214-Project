#ifndef WARENGINE_H
#define WARENGINE_H
#include <vector>
#include "Country.h"
#include "Memento.h"
#include "WarMap.h"
#include "WarPhase.h"

using namespace std;

class Memento;

class WarEngine
{
private:
	vector<Country*> countryGroup;
    vector<Area*> warTheatreGraph;
    WarMap map;
public:
    WarEngine(vector<Country*> countryGroup, vector<Area*> warTheatreGraph, WarMap map);
    void run(string Mode);
    Memento* createMemento();
    Country pickCountry();
    vector<Area*> getWarTheatreGraph();
    vector<Country*> getCountryGroup();
    void setWarTheatreGraph(vector<Area*> newWarTheatreGraph);
    void setCountryGroup(vector<Country*> newCountryGroup);
    Country* getCountryAt(int index);
    void removeCountryAt(int index);
    Area* getAreaAt(int index);
    void removeAreaAt(int index);
    void reinstateMemento(Memento *memento);
    void addCountry(Country* newCountry);
    void addArea(Area* newArea);
    void setWarMap(WarMap newMap);
};

#endif