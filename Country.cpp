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

Country::Country(Country &country, Communication *comm, AssociatedCountries *parent)
{
    this->tele = comm;
    this->tele->storeMe(this);
    this->name = country.name;
    this->numCitzenGroups = country.numCitzenGroups;
    this->parent = parent;

    for (auto a : this->areas)
    {
        this->areas.push_back(a->clone(this));
    }

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
    int x = 0;
    for (auto t : entities->getTroops())
    {
        this->citizens[x++] = t->getAssociatedCitizen();
    }
}

std::string Country::getName()
{
    return name;
}

std::list<Area *> Country::getAreas()
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
    std::list<Area *>::iterator it;
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
    std::list<Area *>::iterator it;
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
    removeAssociatedCountries(this);
    delete entities;
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

AssociatedCountries *Country::clone(Communication *comm, AssociatedCountries *parent)
{
    return new Country(*this, comm, parent);
}

list<Country *> Country::getAllies()
{
    Relationship *rel = (Relationship *)getParent();
    list<Country *> allies;
    if (rel == nullptr)
    {
        return allies;
    }

    for (int i = 0; i < rel->getRelationships().size(); i++)
    {
        if (Relationship *relationship = dynamic_cast<Relationship *>(rel->getRelationships().at(i)))
        {
            list<Country *> empty;
            return empty;
        }
        else
        {
            allies.push_back((Country *)rel->getRelationships().at(i));
        }
    }
    return allies;
}

list<Country *> Country::getEnemies()
{
    Relationship *relAllies = (Relationship *)getParent();
    Relationship *relEnemies;
    list<Country *> enemies;
    if (relAllies == nullptr)
    {
        return enemies;
    }
    string alliesName = relAllies->getRelationshipType();
    Relationship *relParent = (Relationship *)getParent();
    if (relParent == nullptr)
    {
        return enemies;
    }
    for (int i = 0; i < relParent->getRelationships().size(); i++)
    {
        if (Relationship *relationship = dynamic_cast<Relationship *>(relParent->getRelationships().at(i)))
        {
            Relationship *r = (Relationship *)relationship->getRelationships().at(i);
            if (r->getRelationshipType() != alliesName)
            {
                relEnemies = (Relationship *)relParent->getRelationships().at(i);
                for (int i = 0; i < relEnemies->getRelationships().size(); i++)
                {
                    if (Relationship *relationship = dynamic_cast<Relationship *>(relEnemies->getRelationships().at(i)))
                    {
                        list<Country *> empty;
                        return empty;
                    }
                    else
                    {
                        enemies.push_back((Country *)relEnemies->getRelationships().at(i));
                    }
                }
            }
        }
    }

    return enemies;
}

void Country::removeCitizen(Citizens *theCitizen)
{
    bool isThere = false;
    for (int i = 0; i < numCitzenGroups; i++)
    {
        if (citizens[i] == theCitizen)
        {
            isThere = true;
            break;
        }
    }
    if (isThere)
    {
        Citizens **temp = citizens;
        citizens = new Citizens *[--numCitzenGroups];
        int x = 0;
        for (int i = 0; i <= numCitzenGroups; i++)
        {
            if (temp[i] != theCitizen)
            {
                citizens[x++] = temp[i];
            }
        }
    }
}