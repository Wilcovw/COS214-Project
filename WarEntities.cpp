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
WarEntities *WarEntities::clone() {
    WarEntities* newEntities = new WarEntities();
	for(auto v: vehicles){
		newEntities->addVehicles(v->clone());
	}

	for(auto t: troops){
		newEntities->addTroops(t->clone());
	}

	for(auto i: infrastructure){
		newEntities->addInfrastructure(i->clone());
	}

	return newEntities;
}
