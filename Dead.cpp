#include "Dead.h"

void Dead::handleChange(Citizens* c) {
    c->setStatus(new Dead());
}

string Dead::getStatus() {
    return "Dead";
}