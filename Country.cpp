#include "Country.h"
#include "Relationship.h"
#include "Communication.h"
#include <iostream>
#include <cstdlib>

Country::Country(std::string name, Communication *t)
{
    tele = t;
    this->name = name;
    tele->storeMe(this);

    numCitzenGroups = 5 + (rand() % 10);

    citizens = new Citizens *[numCitzenGroups];
    for (int i = 0; i < numCitzenGroups; i++)
    {
        citizens[i] = new Citizens();
    }
}

std::string Country::getName()
{
    return name;
}

// Map Country::getMap()
// {
//     return map;
// }

Citizens **Country::getCitizens()
{
    return citizens;
}

int Country::getNumCitzenGroups()
{
    return numCitzenGroups;
}
// WarEntities Country::getWarEntities()
// {
//     return entities;
// }

// Country::~Country()
// {
//     // for (int i = 0; i < citzens.length; i++)
//     // {
//     //     delete citzens[i];
//     // }
//     // delete citzens;
// }

void Country::receiveMessage(std::string message)
{
    std::cout << name << " received a message: \t" << message << std::endl;
}

void Country::sendBroadcast(AssociatedCountries *messageReceiver, std::string message)
{
    if (Country *country = dynamic_cast<Country *>(messageReceiver))
    {
        std::cout << name << " is sending a message to " << country->getName() << std::endl;
    }
    else if (Relationship *rel = dynamic_cast<Relationship *>(messageReceiver))
    {
        std::cout << name << " is sending a message to " << rel->getRelationshipType() << std::endl;
    }

    tele->notify(messageReceiver, message);
}

AssociatedCountries *Country::getParent()
{
    return parent;
}

void Country::setParent(AssociatedCountries *parent)
{
    this->parent = parent;
}

std::string Country::print()
{
    return name;
}

void Country::addAssociatedCountries(AssociatedCountries *al)
{
    parent->addAssociatedCountries(al);
}

void Country::removeAssociatedCountries(AssociatedCountries *al)
{
    parent->removeAssociatedCountries(al);
}

void Country::revolt(bool active)
{
    if (active)
    {
        std::cout << name << "'s citzens have started a revolution!!!" << std::endl;
    }
    else
    {
        std::cout << name << "'s revolution has ended" << std::endl;
    }
}