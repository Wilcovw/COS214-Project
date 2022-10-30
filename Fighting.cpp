#include "Fighting.h"

void Fighting::handleChange(Citizens* c) {
    c->setStatus(new Stationed);
}

string Fighting::getStatus() {
    return "Fighting";
}

void Fighting::die(Citizens* c) {
    cout << "A group of Fighting Citizens died!" << endl;
    c->setStatus(new Dead());
}