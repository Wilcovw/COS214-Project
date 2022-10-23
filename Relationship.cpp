#include "Relationship.h"
#include "Country.h"
#include "Communication.h"
#include <iostream>
#include <algorithm>

Relationship::Relationship(std::string r, Communication *t)
{
    tele = t;
    relationshipType = r;
    tele->storeMe(this);
}

std::string Relationship::getRelationshipType()
{
    return relationshipType;
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

void Relationship::receiveMessage(std::string message)
{
    tele->notify(this, message);
}

void Relationship::sendBroadcast(AssociatedCountries *messageReceiver, std::string message)
{
    if (Country *country = dynamic_cast<Country *>(messageReceiver))
    {
        std::cout << relationshipType << " is sending a message to " << country->getName() << std::endl;
    }
    else if (Relationship *rel = dynamic_cast<Relationship *>(messageReceiver))
    {
        std::cout << relationshipType << " is sending a message to " << rel->getRelationshipType() << std::endl;
    }
    tele->notify(messageReceiver, message);
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
            std::string str = relationship->print();
            str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
            out += str + "\n";
        }
        else if (Country *country = dynamic_cast<Country *>(*it))
        {
            out += country->print() + ", ";
        }
    }
    out = out.substr(0, out.length() - 2);
    out += "\n";
    return out;
}