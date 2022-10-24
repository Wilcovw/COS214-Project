#include "Dead.h"

void Dead::handleChange(Citizens *c)
{
    c->setStatus(new Dead());
}

string Dead::getStatusReport(Citizens *c)
{
    stringstream ss;
    ss << "Dead Citizens: " << c->getNumberCitizens() << " people";

    return ss.str();
}