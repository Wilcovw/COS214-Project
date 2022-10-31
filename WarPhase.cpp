#include "WarPhase.h"

WarPhase::WarPhase(vector<Country*> countryGroup, vector<Area*> warTheatreGraph, WarMap map){
    this->countryGroup = countryGroup;
    this->warTheatreGraph = warTheatreGraph;
    this->map = map;
};

vector<Country*> WarPhase::getCountryGroup(){
    return  this->countryGroup;
};

vector<Area*> WarPhase::getWarTheatreGraph(){
    return this->warTheatreGraph;
};

WarMap WarPhase::getMap(){
    return this-> map;
};