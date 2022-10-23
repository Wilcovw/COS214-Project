#include "Relationship.h"
#include "Country.h"
#include "Communication.h"
#include <iostream>
#include <algorithm>

Relationship::Relationship(std::string r)
{
    relationshipType = r;
}

void Relationship::addAssociatedCountries(AssociatedCountries *al)
{
    al->setParent(this);
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

AssociatedCountries *Relationship::getParent()
{
    return parent;
}

void Relationship::setParent(AssociatedCountries *parent)
{
    this->parent = parent;
}

std::string Relationship::print()
{
    std::string out = relationshipType + ": \n";
    std::vector<AssociatedCountries *>::iterator it;
    for (it = alliances.begin(); it != alliances.end(); ++it)
    {
        if (Relationship *relationship = dynamic_cast<Relationship *>(*it))
        {
            std::string str = (*it)->print();
            str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
            out += str + "\n";
        }
        else if (Country *relationship = dynamic_cast<Country *>(*it))
        {
            out += (*it)->print() + ", ";
        }
    }
    out = out.substr(0, out.length() - 2);
    out += "\n";
    return out;
}