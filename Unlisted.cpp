#include "Unlisted.h"

void Unlisted::handleChange(Citizens* c) {
    c->setStatus(new Enlisted());
}

string Unlisted::getStatus() {
    return "Unlisted";
}