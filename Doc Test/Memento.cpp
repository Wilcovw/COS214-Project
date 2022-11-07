#include "Memento.h"
#include "WarPhase.h"
#include <iostream>

Memento::Memento(WarPhase *currentPhase)
{
    this->warphase = currentPhase;
}

Memento::~Memento()
{
    delete warphase;
    warphase = 0;
}
