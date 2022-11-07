#include <vector>
#include <iostream>
#include "WarHistory.h"
#include "Memento.h"

WarHistory::WarHistory(){

};

Memento *WarHistory::getLastMemento()
{
    if(history.empty()) return nullptr;
    Memento *temp = history.front();
    this->history.pop_front();
    return temp;
};

void WarHistory::storeMemento(Memento *memento)
{
    this->history.push_front(memento);
};

list<Memento *> WarHistory::getEntireHistory()
{
    return this->history;
};
