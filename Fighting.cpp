#include "Fighting.h"

void Fighting::handleChange(Citizens* c) {
    c->setStatus(new Stationed);
}

string Fighting::getStatus() {
    return "Fighting";
}