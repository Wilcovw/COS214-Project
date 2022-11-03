#include "WarEngine.h"
#include "WarEntities.h"
#include "Country.h"
#include "CommunicationBroadcast.h"
#include "Road.h"
#include "Harbour.h"
#include "Runway.h"
#include "LandVehicleDevelopment.h"
#include "AquaticVehicleDevelopment.h"
#include "AircraftDevelopment.h"
#include "LandVehicleFactory.h"
#include "AquaticVehicleFactory.h"
#include "AircraftFactory.h"
#include "GroundTroopTraining.h"
#include "NavyTraining.h"
#include "AirforceTraining.h"
#include "Memento.h"
#include <set>
#include <tuple>
#include <typeindex>
#include <iostream>
using namespace std;

WarEngine::WarEngine() {
    map = new WarMap();
    communication = new CommunicationBroadcast();
};

WarEngine::~WarEngine() {
    for(auto c : allCountries) {
        delete c;
    }
    delete map;
    delete communication;
}

void WarEngine::addCountry(string name, int numCitizens) {
    if(communication != nullptr) {
        allCountries.push_back(new Country(name, communication, numCitizens));
    }
};

Country* WarEngine::getCountry(string countryName) {
    if(!allCountries.empty()) {
        for(auto c : allCountries) {
            if(c->getName() == countryName) {
                return c;
            }
        }
    }
    return nullptr;
};

Country* WarEngine::getCountryFromArea(string areaName) {
    if(!allCountries.empty()) {
        for(auto c : allCountries) {
            Country* temp = c;
            for(auto a : temp->getAreas()) {
                if(a->getName() == areaName) {
                    return c;
                }
            }
        }
    }
    return nullptr;
}

void WarEngine::addArea(string areaName, string countryName) {
    if(getCountry(countryName) != nullptr) {
        Area * newArea = new Area(areaName, getCountry(countryName));
        getCountry(countryName)->addArea(newArea);
        map->addArea(newArea);
    }
};

Area* WarEngine::getArea(string areaName) {
    return map->getArea(areaName);
}

//TODO: change HP values
void WarEngine::addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance) {
    Country* country = getCountryFromArea(sourceName);
    Country* destination = getCountryFromArea(destinationName);
    if(country != nullptr && destination != nullptr) {
        if(type == ::iRoad) {
            Road* newRoad = new Road(getArea(sourceName), getArea(destinationName), 3, distance);
        }
        else if(type == ::iHarbour) {
            Harbour* theHarbour;
            Harbour* theOtherHarbour;
            if(getInfrastructureInArea(sourceName,  type).empty()){
                theHarbour = new Harbour(getArea(sourceName),3);
                country->getWarEntities()->addInfrastructure(theHarbour);
            } else {
                theHarbour = (Harbour*)getInfrastructureInArea(sourceName,  type).front();
            }
            if(getInfrastructureInArea(destinationName, type).empty()) {
                theOtherHarbour = new Harbour(getArea(destinationName),3);
                destination->getWarEntities()->addInfrastructure(theOtherHarbour);
            } else {
                theOtherHarbour = (Harbour*)getInfrastructureInArea(destinationName,  type).front();
            }
            theHarbour->addConnection(getArea(destinationName), distance, theOtherHarbour);
        } else if(type == ::iRunway) {
            Runway* theRunway;
            Runway* theOtherRunway;
            if(getInfrastructureInArea(sourceName, type).empty()){
                theRunway = new Runway(getArea(sourceName),3);
                country->getWarEntities()->addInfrastructure(theRunway);
            } else {
                theRunway = (Runway*)getInfrastructureInArea(sourceName,  type).front();
            }
            if(getInfrastructureInArea(destinationName, type).empty()) {
                theOtherRunway = new Runway(getArea(destinationName), 3);
                destination->getWarEntities()->addInfrastructure(theOtherRunway);
            } else {
                theOtherRunway = (Runway*)getInfrastructureInArea(destinationName, type).front();
            }
            theRunway->addConnection(getArea(destinationName), distance, theOtherRunway);
        }
    }
    else {
        cout<< "Location was not found" << endl;
    }
}

//TODO: change HP values
void WarEngine::addInfrastructure(typeOfInfrastructure type, string areaName) {
    Country* country = getCountryFromArea(areaName);
    if(country != nullptr) {
        if(type == ::iRoad) {
            cout << "Road cannot be created using this function, please call function addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double length)" << endl;
        } else if(type == ::iHarbour) {
            country->getWarEntities()->addInfrastructure(new Harbour(getArea(areaName), 3));
        } else if(type == ::iRunway) {
            country->getWarEntities()->addInfrastructure(new Runway(getArea(areaName), 3)); 
        } else if(type == ::iLandDevlopment) {
            country->getWarEntities()->addInfrastructure(new LandVehicleDevelopment(15, getArea(areaName)));
        } else if(type == ::iAquaticDevelopment) {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleDevelopment(15, getArea(areaName)));
        } else if(type == ::iAircraftDevelopment) {
            country->getWarEntities()->addInfrastructure(new AircraftDevelopment(15, getArea(areaName)));
        } else if(type == ::iLandFactory) {
            country->getWarEntities()->addInfrastructure(new LandVehicleFactory(15, getArea(areaName)));
        } else if(type == ::iAquaticFactory) {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleFactory(15, getArea(areaName)));
        } else if(type == ::iAircraftFactory) {
            country->getWarEntities()->addInfrastructure(new AircraftDevelopment(15, getArea(areaName)));
        } else if(type == ::iGroundCamp) {
            country->getWarEntities()->addInfrastructure(new GroundTroopTraining(15, getArea(areaName)));
        } else if(type == ::iNavyCamp) {
            country->getWarEntities()->addInfrastructure(new NavyTraining(15, getArea(areaName)));
        } else if(type == ::iAirforceCamp) {
            country->getWarEntities()->addInfrastructure(new AirforceTraining(15, getArea(areaName)));
        }
    } else {
        cout << "The location was not found" << endl;
    }
}

list<Infrastructure*> WarEngine::getInfrastructureInArea(string areaName, typeOfInfrastructure type) {
    list<Infrastructure*> output;
    Country* country = getCountryFromArea(areaName);
    if(country != nullptr && !country->getWarEntities()->getInfrastructure().empty()) {
        list<Infrastructure*> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for(auto i : allInfrastructure) {
            Infrastructure* temp = i;
            if(type == temp->getType() && i->getArea()->getName() == areaName) {
                output.push_back(temp);
            }
        }
    }
    return output;
}

void run(string Mode){
    //TODO
    cout<< "War mode " + Mode + " activated"<<endl;
};

Country WarEngine::pickCountry(){
    //TODO
    return  *this->allCountries.at(0);
};

void WarEngine::removeCountryAt(int index){
    this->allCountries.erase(this->allCountries.begin()+index);
};

void WarEngine::setWarMap(WarMap* newMap){
    this->map = newMap;
};

void WarEngine::setCountryGroup(vector<Country*> newCountryGroup){
    this->allCountries = newCountryGroup;
};

vector<Country*> WarEngine::getCountryGroup(){
    return this->allCountries;;
};

Memento* WarEngine::createMemento(){
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

void WarEngine::reinstateMemento(Memento* memento){
    WarPhase* oldphase = memento->warphase;

    this->allCountries = oldphase->getCountryGroup();
    this->map = oldphase->getMap();
};