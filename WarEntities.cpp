#include "WarEntities.h"

WarEntities::WarEntities()
{
}
WarEntities::~WarEntities()
{
    std::vector<Vehicles *>::iterator it;
    for (it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        delete *it;
    }
    std::vector<Troops *>::iterator itt;
    for (itt = troops.begin(); itt != troops.end(); ++itt)
    {
        delete *itt;
    }
    std::vector<Infrastructure *>::iterator iti;
    for (iti = infrastructure.begin(); iti != infrastructure.end(); ++iti)
    {
        delete *iti;
    }
}

WarEntities::WarEntities(WarEntities &warEnt)
{
    for (int i = 0; i < warEnt.vehicles.size(); i++)
    {
        this->vehicles.push_back(warEnt.vehicles.at(i)->clone());
    }
    for (int i = 0; i < warEnt.troops.size(); i++)
    {
        this->troops.push_back(warEnt.troops.at(i)->clone());
    }
    for (int i = 0; i < warEnt.infrastructure.size(); i++)
    {
        this->infrastructure.push_back(warEnt.infrastructure.at(i)->clone());
    }
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

std::vector<Vehicles *> WarEntities::getVehicles()
{
    return vehicles;
}

std::vector<Troops *> WarEntities::getTroops()
{
    return troops;
}

std::vector<Infrastructure *> WarEntities::getInfrastructure()
{
    return infrastructure;
}

WarEntities *WarEntities::clone()
{
    return new WarEntities(*this);
}