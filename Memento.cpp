#include "Memento.h"
#include <iostream>

Memento::Memento(vector<Country*> allCountries, Communication* communication, WarMap* map){
    this->warphase = new WarPhase(allCountries, communication, map);
};

Memento::~Memento(){
    delete warphase;
    warphase = 0;
};


