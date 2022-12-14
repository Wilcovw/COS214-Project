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
    for(int i = 0; i < numCitzenGroups; i++) {
        citizens.push_back(new Citizens());
    }
}

Country::Country()
{
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
    areas.remove(area);
}

list<Citizens*> Country::getCitizens()
{
    return citizens;
}

WarEntities *Country::getWarEntities()
{
    return entities;
}

Country::~Country()
{
    removeAssociatedCountries(this);
    delete entities;
    for(auto c : citizens) {
        delete c;
    }
}

void Country::receiveMessage(std::string message)
{
    std::cout << name << " received a message: \t" << message << std::endl;
	recivedMessage = message;
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
    Country *newCountry = new Country();
    newCountry->tele = comm;
    newCountry->tele->storeMe(newCountry);
    newCountry->name = this->name;
    newCountry->parent = parent;
    newCountry->entities = new WarEntities();
    return newCountry;
}

void Country::cloneWarEntities(Country *country)
{
    int counter = 0;
    for(auto c : citizens) {
        if(c != nullptr && c->getStatus() =="Unlisted" || c->getStatus() == "Dead")
        {
            country->citizens.push_back(c->clone());
        }
    }
    int x = 0;
    country->entities = this->entities->clone();
    for (auto t : this->entities->getTroops())
    {
        country->citizens.push_back(t->getAssociatedCitizen());
    }
}

list<Country *> Country::getAllies()
{
    Relationship *rel = (Relationship *)getParent();
    list<Country *> allies;
    if (rel == nullptr)
    {
        return allies;
    }
    for (auto r : rel->getRelationships())
    {
        if (Relationship *relationship = dynamic_cast<Relationship *>(r))
        {
            list<Country *> empty;
            return empty;
        }
        else
        {
            allies.push_back((Country *)r);
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
    for (auto r : relParent->getRelationships())
    {
        if (Relationship *relationship = dynamic_cast<Relationship *>(r))
        {
            Relationship *rel = (Relationship *)r;
            if (rel->getRelationshipType() != alliesName)
            {
                relEnemies = (Relationship *)r;
                // for (int i = 0; i < relEnemies->getRelationships().size(); i++)
                for (auto rTemp : relEnemies->getRelationships())
                {
                    if (Relationship *relationship = dynamic_cast<Relationship *>(rTemp))
                    {
                        list<Country *> empty;
                        return empty;
                    }
                    else
                    {
                        enemies.push_back((Country *)rTemp);
                    }
                }
            }
        }
    }

    return enemies;
}

Communication *Country::getCommunication()
{
    return tele;
}

void Country::removeCitizen(Citizens *theCitizen)
{
    citizens.remove(theCitizen);
}