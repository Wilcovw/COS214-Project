#include "Memento.h"
#include "WarMap.h"
#include "WarPhase.h"
#include "Country.h"
#include "Communication.h"
#include <iostream>

Memento::Memento(vector<Country*> allCountries, Communication* communication, WarMap* map){
    this->warphase = new WarPhase();
};

Memento::~Memento(){
    delete warphase;
    warphase = 0;
};


