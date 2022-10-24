#include "Enlisted.h"

void Enlisted::handleChange(Citizens *c)
{
    c->setStatus(new Enlisted());
}

string Enlisted::getStatusReport(Citizens *c)
{
    stringstream ss;
    ss << "Enlisted Citizens: " << c->getNumberCitizens() << " people";

    return ss.str();
}