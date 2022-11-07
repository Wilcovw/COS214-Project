#include "Unlisted.h"

void Unlisted::handleChange(Citizens* c) {
    c->setStatus(new Enlisted());
}

string Unlisted::getStatus() {
    return "Unlisted";
}

void Unlisted::die(Citizens* c) {
    // cout << "A group of Unlisted Citizens died!" << endl;
    c->setStatus(new Dead());
}