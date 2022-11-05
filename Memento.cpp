#include "Memento.h"
#include <iostream>

Memento::Memento(WarPhase* currentPhase){
    this->warphase = currentPhase;
}

Memento::~Memento(){
    delete warphase;
    warphase = 0;
}


