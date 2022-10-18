#include "Relationship.h"
#include <iostream>

Relationship::Relationship(std::string r)
{
    relationshipType = r;
}

void Relationship::addAssociatedCountries(AssociatedCountries *al)
{
    alliances.push_back(al);
}

void Relationship::removeAssociatedCountries(AssociatedCountries *al)
{
    std::vector<AssociatedCountries *>::iterator it;
    for (it = alliances.begin(); it != alliances.end(); ++it)
    {
        if (al == *it)
        {
            alliances.erase(it);
        }
    }
}

std::vector<AssociatedCountries *> Relationship::getRelationships()
{
    return alliances;
}

Relationship::~Relationship()
{
    std::vector<AssociatedCountries *>::iterator it;
    for (it = alliances.begin(); it != alliances.end(); ++it)
    {
        delete *it;
    }
}

void Relationship::receiveMessage(std::string mess)
{
    std::cout << mess << std::endl;
}

void Relationship::sendBroadcast()
{
    tele->notify(this);
}