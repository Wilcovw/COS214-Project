#include "WarEngine.h"
#include <iostream>

WarEngine::WarEngine(vector<Country*> countryGroup, vector<Area*> warTheatreGraph, WarMap map){
    this->countryGroup = countryGroup;
    this->warTheatreGraph = warTheatreGraph;
    this->map = map;
};

void run(string Mode){
    //TODO
    cout<< "War mode " + Mode + " activated"<<endl;
};

Country WarEngine::pickCountry(){
    //TODO
    return  *this->countryGroup.at(0);
};

void WarEngine::addCountry(Country* newCountry){
    this->countryGroup.push_back(newCountry);
};

void WarEngine::addArea(Area* newArea){
    this->warTheatreGraph.push_back(newArea);
};

void WarEngine::removeCountryAt(int index){
    this->countryGroup.erase(this->countryGroup.begin()+index);
};

void WarEngine::removeAreaAt(int index){
    this->warTheatreGraph.erase(this->warTheatreGraph.begin()+index);
};

Country* WarEngine::getCountryAt(int index){
    return this->countryGroup.at(index);
};

Area* WarEngine::getAreaAt(int index){
    return this->warTheatreGraph.at(index);
};

void WarEngine::setWarMap(WarMap newMap){
    this->map = newMap;
};

void WarEngine::setCountryGroup(vector<Country*> newCountryGroup){
    this->countryGroup = newCountryGroup;
};

void WarEngine::setWarTheatreGraph(vector<Area*> newWarTheatreGraph){
    this->warTheatreGraph = newWarTheatreGraph;
};

vector<Area*> WarEngine::getWarTheatreGraph(){
    return this->warTheatreGraph;
};

vector<Country*> WarEngine::getCountryGroup(){
    return this->countryGroup;;
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

    this->countryGroup = oldphase->getCountryGroup();
    this->warTheatreGraph = oldphase->getWarTheatreGraph();
    this->map = oldphase->getMap();
};

