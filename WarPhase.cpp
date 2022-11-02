#include "WarPhase.h"

WarPhase::WarPhase(vector<Country*> allCountries, Communication* c, WarMap* map){
    this->allCountries = allCountries;
    this->map = map;
};

vector<Country*> WarPhase::getCountryGroup(){
    return  this->allCountries;
};

Communication* WarPhase::getCommunication(){
    return this->communication;
};

WarMap* WarPhase::getMap(){
    return this-> map;
};