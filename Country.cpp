#include "Country.h"
#include "Relationship.h"
#include "Communication.h"
#include "WarEntities.h"
#include <iostream>
#include <cstdlib>

Country::Country(std::string name, Communication *t, int numCitzenGroups)
{
    tele = t;
    this->name = name;
    tele->storeMe(this);
    entities = new WarEntities();

    this->numCitzenGroups = numCitzenGroups;
    citizens = new Citizens *[numCitzenGroups];
    for (int i = 0; i < numCitzenGroups; i++)
    {
        citizens[i] = new Citizens();
    }
}

Country::Country(Country &country, Communication *comm)
{
    this->tele = comm;
    this->tele->storeMe(this);
    this->name = country.name;
    this->numCitzenGroups = country.numCitzenGroups;

    this->citizens = new Citizens *[country.numCitzenGroups];
    int counter = 0;
    for (int i = 0; i < numCitzenGroups; i++)
    {
        if (country.citizens[i]->getStatus().compare("Unlisted") || country.citizens[i]->getStatus().compare("Dead"))
        {
            this->citizens[counter] = country.citizens[i]->clone();
            counter++;
        }
    }
    this->entities = country.entities->clone();
    for (int i = 0; i < entities->getTroops().size(); i++)
    {
        this->citizens[counter] = entities->getFightingCitizens().at(i);
    }

    // Temporary code: might need to receive cloned areas instead of creating new ones here, cause they not setup properly
    for (int i = 0; i < country.areas.size(); i++)
    {
        this->areas.push_back(country.areas.at(i)->clone(this));
    }
}

std::string Country::getName()
{
    return name;
}

std::vector<Area *> Country::getAreas()
{
    return areas;
}

void Country::addArea(Area *area)
{
    areas.push_back(area);
}

std::string Country::printAreas()
{
    std::string out = "Areas controlled by " + name + ": ";
    std::vector<Area *>::iterator it;
    for (it = areas.begin(); it != areas.end(); ++it)
    {
        out += (*it)->getName() + ", ";
    }
    out = out.substr(0, out.length() - 2);
    out += "\n";
    return out;
}

void Country::removeArea(Area *area)
{
    std::vector<Area *>::iterator it;
    for (it = areas.begin(); it != areas.end(); ++it)
    {
        if (area == *it)
        {
            areas.erase(it);
        }
    }
}

Citizens **Country::getCitizens()
{
    return citizens;
}

int Country::getNumCitzenGroups()
{
    return numCitzenGroups;
}

WarEntities *Country::getWarEntities()
{
    return entities;
}

Country::~Country()
{
    std::vector<Area *>::iterator it;
    for (it = areas.begin(); it != areas.end(); ++it)
    {
        delete *it;
    }

    for (int i = 0; i < numCitzenGroups; i++)
    {
        delete citizens[i];
    }
    delete citizens;
}

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

AssociatedCountries *Country::clone(Communication *comm)
{
    return new Country(*this, comm);
}