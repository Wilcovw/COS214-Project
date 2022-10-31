#include <vector>
#include <iostream>
#include "WarHistory.h"

WarHistory::WarHistory(){

};

Memento* WarHistory::getMementoAt(int index){
    return this->warhistory.at(index);
};

Memento* WarHistory::getLastMemento(){
    return this->warhistory.back();
};

void WarHistory::storeMemento(Memento* memento){
    this->warhistory.push_back(memento);
};

vector<Memento*> WarHistory::getEntireHistory(){
    return this->warhistory;
};



