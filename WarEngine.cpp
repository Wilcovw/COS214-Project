#ifndef WARENGINE_CPP
#define WARENGINE_CPP
#include "WarEngine.h"
#include "WarPhase.h"
#include "Country.h"
#include "Relationship.h"
#include "Area.h"
#include "Infrastructure.h"
#include "Troops.h"
#include "Vehicles.h"
#include "WarHistory.h"

WarEngine::WarEngine()
{
    phase = new WarPhase();
    history = new WarHistory();
};

WarEngine::~WarEngine()
{
    delete phase;
}

void WarEngine::newWarPhase()
{
    history->storeMemento(phase->newWarPhase());
}

void WarEngine::reverseWarPhase()
{
    phase->reverseWarPhase(history->getLastMemento());
}

WarPhase *WarEngine::getPhase()
{
    return phase;
}

/*
void WarEngine::setCountryGroup(list<Country *> newCountryGroup)
{
    phase->setCountryGroup(newCountryGroup);
}

list<Country *> WarEngine::getCountryGroup()
{
    return phase->getCountryGroup();
}


Memento *WarEngine::createMemento()
{
    // vector<Country*> newCountryGroup;
    // vector<Area*> newWarTheatreGraph;
    // WarMap* newMap = new WarMap();

    // for(int i = 0; i < this->countryGroup.size(); i++){
    //     newCountryGroup.push_back(this->countryGroup.at(i)->clone());
    // }
    // for(int i = 0; i < this->warTheatreGraph.size(); i++){
    //     newWarTheatreGraph.push_back(this->warTheatreGraph.at(i)->clone());
    // }
    // return new Memento(newCountryGroup, newWarTheatreGraph, newMap);
    return nullptr;
};

void WarEngine::reinstateMemento(Memento *memento){
    // WarPhase *oldphase = memento->warphase;

    // this->allCountries = oldphase->getCountryGroup();
    // this->map = oldphase->getMap();
};*/

#endif