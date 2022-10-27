#include "Enlisted.h"

void Enlisted::handleChange(Citizens* c) {
    c->setStatus(new Stationed());
}

string Enlisted::getStatus() {
    return "Enlisted";
}