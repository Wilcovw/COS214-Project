#include <vector>
#include <iostream>
#include "WarHistory.h"
#include "Memento.h"

WarHistory::WarHistory(){

};

Memento *WarHistory::getLastMemento()
{
    Memento *temp = history.front();
    this->history.pop_front();
    return temp;
};

void WarHistory::storeMemento(Memento *memento)
{
    this->history.push_back(memento);
};

list<Memento *> WarHistory::getEntireHistory()
{
    return this->history;
};
