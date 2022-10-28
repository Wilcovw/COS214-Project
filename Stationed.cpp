#include "Stationed.h"

void Stationed::handleChange(Citizens* c) {
    c->setStatus(new Fighting());
}

string Stationed::getStatus() {
    return "Stationed";
}

void Stationed::die(Citizens* c){
    cout << "A group of Stationed Citizens died!" << endl;
    c->setStatus(new Dead());
}