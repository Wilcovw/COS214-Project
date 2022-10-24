#include "Fighting.h"

void Fighting::handleChange(Citizens *c)
{
    c->setStatus(new Stationed());
}

string Fighting::getStatusReport(Citizens *c)
{
    stringstream ss;
    ss << "Fighting Citizens: " << c->getNumberCitizens() << " people";

    return ss.str();
}