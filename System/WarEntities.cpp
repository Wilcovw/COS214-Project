#include "WarEntities.h"
WarEntities::WarEntities()
{
}
WarEntities::~WarEntities()
{
    for (auto v : vehicles)
    {
        delete v;
    }

    for (auto t : troops)
    {
        delete t;
    }

    infrastructure.sort();
    infrastructure.unique();
    for (auto i : infrastructure)
    {
        delete i;
    }
}

WarEntities *WarEntities::clone()
{
    WarEntities *newEntities = new WarEntities();
    for (auto v : vehicles)
    {
        newEntities->addVehicles(v->clone(v->getLocation()->getClonedArea()));
    }
    for (auto t : troops)
    {
        newEntities->addTroops(t->clone(t->getLocation()->getClonedArea()));
    }
    int num = 0;
    for (auto i : infrastructure)
    {
        if (i != nullptr && i->getArea() != nullptr && i->getArea()->getClonedArea() != nullptr)
        {
            Infrastructure *in = i->clone(i->getArea()->getClonedArea());
            if (in != nullptr)
            {
                newEntities->addInfrastructure(in);
            }
        }
    }
    return newEntities;
}

void WarEntities::addVehicles(Vehicles *theVehicle)
{
    vehicles.push_back(theVehicle);
}

void WarEntities::addTroops(Troops *theTroop)
{
    troops.push_back(theTroop);
}

void WarEntities::addInfrastructure(Infrastructure *theInfrastructure)
{
    infrastructure.push_back(theInfrastructure);
}

std::list<Vehicles *> WarEntities::getVehicles()
{
    return vehicles;
}

std::list<Troops *> WarEntities::getTroops()
{
    return troops;
}

std::list<Infrastructure *> WarEntities::getInfrastructure()
{
    return infrastructure;
}

void WarEntities::removeInfrastructure(Infrastructure *theObject)
{
    infrastructure.remove(theObject);
}

void WarEntities::removeTroops(Troops *theTroop)
{
    troops.remove(theTroop);
}

void WarEntities::removeVehicles(Vehicles *theVehicle)
{
    vehicles.remove(theVehicle);
}

std::list<Citizens *> WarEntities::getFightingCitizens()
{
    std::list<Citizens *> list;
    for (int i = 0; i < troops.size(); i++)
    {
        list.push_back(troops.front()->getAssociatedCitizen());
    }
    return list;
}