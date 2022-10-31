#include "Memento.h"
#include <iostream>

Memento::Memento(vector<Country*> countryGroup, vector<Area*> warTheatreGraph, WarMap map){
    this->warphase = new WarPhase(countryGroup, warTheatreGraph, map);
};

Memento::~Memento(){
    delete warphase;
    warphase = 0;
};


