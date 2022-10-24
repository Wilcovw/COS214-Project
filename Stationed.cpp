#include "Stationed.h"

void Stationed::handleChange(Citizens *c)
{
    c->setStatus(new Stationed());
}

string Stationed::getStatusReport(Citizens *c)
{
    string out = "Stationed Citizens: ";
    stringstream ss;
    ss << out << c->getNumberCitizens() << " people";

    return ss.str();
}

void Stationed::die(Citizens *c) {
    c->setStatus(new Dead);
}