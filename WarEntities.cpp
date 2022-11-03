#include "WarEntities.h"
WarEntities::WarEntities()
{
}
WarEntities::~WarEntities()
{
    std::list<Vehicles *>::iterator it;
    for (it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        delete *it;
    }

    std::list<Troops *>::iterator itt;
    for (itt = troops.begin(); itt != troops.end(); ++itt)
    {
        delete *itt;
    }

    std::list<Infrastructure *>::iterator iti;
    for (iti = infrastructure.begin(); iti != infrastructure.end(); ++iti)
    {
        delete *iti;
    }
}

WarEntities *WarEntities::clone()
{
    WarEntities *newEntities = new WarEntities();
    for (auto v : vehicles)
    {
        newEntities->addVehicles(v->clone());
    }

    for (auto t : troops)
    {
        newEntities->addTroops(t->clone());
    }

    for (auto i : infrastructure)
    {
        if (i->getArea()->getClonedArea() != nullptr)
        {
            newEntities->addInfrastructure(i->clone(i->getArea()->getClonedArea()));
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

std::list<Citizens *> WarEntities::getFightingCitizens()
{
    std::list<Citizens *> ans;
    for (auto t : troops)
    {
    }

    return ans;
}

void WarEntities::removeInfrastructure(Infrastructure * theObject) {
    infrastructure.remove(theObject);
}