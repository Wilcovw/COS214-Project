#include "Unlisted.h"

void Unlisted::handleChange(Citizens *c)
{
    c->setStatus(new Enlisted());
}

string Unlisted::getStatusReport(Citizens *c)
{
    stringstream ss;
    ss << "Unlisted Citizens: " << c->getNumberCitizens() << " people";

    return ss.str();
}

void Unlisted::die(Citizens *c) {
    c->setStatus(new Dead);
}