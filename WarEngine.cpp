#include "WarEngine.h"
#include "WarEntities.h"
#include "Country.h"
#include "CommunicationBroadcast.h"
#include "Road.h"
#include "Harbour.h"
#include "Runway.h"
#include "LandVehicleDevelopment.h"
#include "AquaticVehicleDevelopment.h"
#include "AircraftDevelopment.h"
#include "LandVehicleFactory.h"
#include "AquaticVehicleFactory.h"
#include "AircraftFactory.h"
#include "GroundTroopTraining.h"
#include "NavyTraining.h"
#include "AirforceTraining.h"
#include "Memento.h"
#include "Soldiers.h"
#include "Generals.h"
#include "Medics.h"
#include "Troops.h"
#include "LandVehicles.h"
#include "AquaticVehicleFactory.h"
#include "AircraftFactory.h"
#include <set>
#include <tuple>
#include <typeindex>
#include <iostream>
using namespace std;

WarEngine::WarEngine()
{
    map = new WarMap();
    communication = new CommunicationBroadcast();
};

WarEngine::~WarEngine()
{
    for (auto c : allCountries)
    {
        delete c;
    }
    delete map;
    delete communication;
}

void WarEngine::addCountry(string name, int numCitizens)
{
    if (communication != nullptr)
    {
        allCountries.push_back(new Country(name, communication, numCitizens));
    }
};

void WarEngine::addRelationship(string relationshipName)
{
    if (getRelationship(relationshipName) == nullptr and communication != nullptr)
    {
        allRelationships.push_back(new Relationship(relationshipName, communication));
    }
}

void WarEngine::addCountrytoRelationship(string countryName, string relationshipName)
{
    Country *country = getCountry(countryName);
    Relationship *relationship = getRelationship(relationshipName);
    relationship->addAssociatedCountries(country);
}

void WarEngine::addRelationshipToRelationship(string relationshipNameParent, string relationshipNameChild)
{
    Relationship *relParent = getRelationship(relationshipNameParent);
    Relationship *relChild = getRelationship(relationshipNameChild);
    relParent->addAssociatedCountries(relChild);
}

Country *WarEngine::getCountry(string countryName)
{
    if (!allCountries.empty())
    {
        for (auto c : allCountries)
        {
            if (c->getName() == countryName)
            {
                return c;
            }
        }
    }
    return nullptr;
};

Relationship *WarEngine::getRelationship(string relationshipName)
{
    if (!allCountries.empty())
    {
        for (auto c : allRelationships)
        {
            if (c->getRelationshipType() == relationshipName)
            {
                return c;
            }
        }
    }
    return nullptr;
}

Country *WarEngine::getCountryFromArea(string areaName)
{
    if (!allCountries.empty())
    {
        for (auto c : allCountries)
        {
            Country *temp = c;
            for (auto a : temp->getAreas())
            {
                if (a->getName() == areaName)
                {
                    return c;
                }
            }
        }
    }
    return nullptr;
}

void WarEngine::addArea(string areaName, string countryName)
{
    if (getCountry(countryName) != nullptr)
    {
        Area *newArea = new Area(areaName, getCountry(countryName));
        getCountry(countryName)->addArea(newArea);
        map->addArea(newArea);
    }
};

Area *WarEngine::getArea(string areaName)
{
    return map->getArea(areaName);
}

list<Area *> WarEngine::getTravelPath(Vehicles *vehicle, string areaName)
{
    list<Area *> result;
    Area *source = vehicle->getLocation();
    Area *destination = getArea(areaName);
    if (vehicle != nullptr)
    {
        if (destination != nullptr || source != nullptr)
        {
            list<Area *> path;
            if (vehicle->getType() == ::landVehicle)
            {
                result = map->shortestPath(source, destination, "Road");
            }
            else if (vehicle->getType() == ::aquaticVehicle)
            {
                result = map->shortestPath(source, destination, "Harbour");
            }
            else if (vehicle->getType() == ::aircraftVehicle)
            {
                result = map->shortestPath(source, destination, "Runwa");
            }
        }
    }
    return result;
}

list<Area *> WarEngine::getTravelPath(Troops *troops, string areaName)
{
    list<Area *> result;
    if (troops != nullptr)
    {
        if (getArea(areaName) != nullptr)
        {
            list<Area *> path;
            if (troops->getKind() == ::tGroundTroops)
            {
                result = map->shortestPath(troops->getLocation(), getArea(areaName), "Road");
            }
            else if (troops->getKind() == ::tAirforce)
            {
                result = map->shortestPath(troops->getLocation(), getArea(areaName), "Runway");
            }
            else if (troops->getKind() == ::tNavy)
            {
                result = map->shortestPath(troops->getLocation(), getArea(areaName), "Harbour");
            }
        }
    }
    return result;
}

double WarEngine::getTravelDistance(Vehicles *vehicle, string areaName)
{
    Area *source = vehicle->getLocation();
    Area *destination = getArea(areaName);
    int distance = -1;
    if (vehicle != nullptr)
    {
        if (destination != nullptr || source != nullptr)
        {
            list<Area *> path;
            if (vehicle->getType() == ::landVehicle)
            {
                path = map->shortestPath(source, destination, "Road");
            }
            else if (vehicle->getType() == ::aquaticVehicle)
            {
                path = map->shortestPath(source, destination, "Harbour");
            }
            else if (vehicle->getType() == ::aircraftVehicle)
            {
                path = map->shortestPath(source, destination, "Runwa");
            }
            if (!path.empty())
            {
                distance = 0;
                for (auto e : path)
                {
                    distance += e->getDist();
                }
            }
        }
    }
    return distance;
}

// TODO: change distance value
void WarEngine::moveVehicles(string areaName, string countryName)
{
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        Area *destination = getArea(areaName);
        if (destination != nullptr)
        {
            list<Vehicles *> vehicles = country->getWarEntities()->getVehicles();
            if (!vehicles.empty())
            {
                for (auto e : vehicles)
                {
                    if (getTravelDistance(e, areaName) <= 200)
                    {
                        e->changeLocation(destination);
                    }
                }
            }
        }
        else
        {
            cout << "Area was not found" << endl;
        }
    }
    else
    {
        cout << "Country was not found" << endl;
    }
}

double WarEngine::getTravelDistance(Troops *troops, string areaName)
{
    double distance = -1;
    if (troops != nullptr)
    {
        if (getArea(areaName) != nullptr)
        {
            list<Area *> path;
            if (troops->getKind() == ::tGroundTroops)
            {
                path = map->shortestPath(troops->getLocation(), getArea(areaName), "Road");
            }
            else if (troops->getKind() == ::tAirforce)
            {
                path = map->shortestPath(troops->getLocation(), getArea(areaName), "Runway");
            }
            else if (troops->getKind() == ::tNavy)
            {
                path = map->shortestPath(troops->getLocation(), getArea(areaName), "Harbour");
            }
            if (!path.empty())
            {
                distance = 0;
                for (auto e : path)
                {
                    distance += e->getDist();
                }
            }
        }
    }
    return distance;
}

// TODO: change distance value
void WarEngine::moveTroops(string areaName, string countryName)
{
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        Area *destination = getArea(areaName);
        if (destination != nullptr)
        {
            list<Troops *> troops = country->getWarEntities()->getTroops();
            if (!troops.empty())
            {
                for (auto t : troops)
                {
                    if (getTravelDistance(t, areaName) <= 100)
                    {
                        t->setLocation(destination);
                    }
                }
            }
        }
        else
        {
            cout << "Area was not found" << endl;
        }
    }
    else
    {
        cout << "Country was not found" << endl;
    }
}

// TODO: change HP values
void WarEngine::addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double distance)
{
    Country *country = getCountryFromArea(sourceName);
    Country *destination = getCountryFromArea(destinationName);
    if (country != nullptr && destination != nullptr)
    {
        if (type == ::iRoad)
        {
            Road *newRoad = new Road(getArea(sourceName), getArea(destinationName), 3, distance);
        }
        else if (type == ::iHarbour)
        {
            Harbour *theHarbour;
            Harbour *theOtherHarbour;
            if (getInfrastructureInArea(sourceName, type).empty())
            {
                theHarbour = new Harbour(getArea(sourceName), 3);
                country->getWarEntities()->addInfrastructure(theHarbour);
            }
            else
            {
                theHarbour = (Harbour *)getInfrastructureInArea(sourceName, type).front();
            }
            if (getInfrastructureInArea(destinationName, type).empty())
            {
                theOtherHarbour = new Harbour(getArea(destinationName), 3);
                destination->getWarEntities()->addInfrastructure(theOtherHarbour);
            }
            else
            {
                theOtherHarbour = (Harbour *)getInfrastructureInArea(destinationName, type).front();
            }
            theHarbour->addConnection(getArea(destinationName), distance, theOtherHarbour);
        }
        else if (type == ::iRunway)
        {
            Runway *theRunway;
            Runway *theOtherRunway;
            if (getInfrastructureInArea(sourceName, type).empty())
            {
                theRunway = new Runway(getArea(sourceName), 3);
                country->getWarEntities()->addInfrastructure(theRunway);
            }
            else
            {
                theRunway = (Runway *)getInfrastructureInArea(sourceName, type).front();
            }
            if (getInfrastructureInArea(destinationName, type).empty())
            {
                theOtherRunway = new Runway(getArea(destinationName), 3);
                destination->getWarEntities()->addInfrastructure(theOtherRunway);
            }
            else
            {
                theOtherRunway = (Runway *)getInfrastructureInArea(destinationName, type).front();
            }
            theRunway->addConnection(getArea(destinationName), distance, theOtherRunway);
        }
    }
    else
    {
        cout << "Location was not found" << endl;
    }
}

// TODO: change HP values
void WarEngine::addInfrastructure(typeOfInfrastructure type, string areaName)
{
    Country *country = getCountryFromArea(areaName);
    if (country != nullptr)
    {
        if (type == ::iRoad)
        {
            cout << "Road cannot be created using this function, please call function addConnection(typeOfInfrastructure type, string sourceName, string destinationName, double length)" << endl;
        }
        else if (type == ::iHarbour)
        {
            country->getWarEntities()->addInfrastructure(new Harbour(getArea(areaName), 3));
        }
        else if (type == ::iRunway)
        {
            country->getWarEntities()->addInfrastructure(new Runway(getArea(areaName), 3));
        }
        else if (type == ::iLandDevlopment)
        {
            country->getWarEntities()->addInfrastructure(new LandVehicleDevelopment(15, getArea(areaName)));
        }
        else if (type == ::iAquaticDevelopment)
        {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleDevelopment(15, getArea(areaName)));
        }
        else if (type == ::iAircraftDevelopment)
        {
            country->getWarEntities()->addInfrastructure(new AircraftDevelopment(15, getArea(areaName)));
        }
        else if (type == ::iLandFactory)
        {
            country->getWarEntities()->addInfrastructure(new LandVehicleFactory(15, getArea(areaName)));
        }
        else if (type == ::iAquaticFactory)
        {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleFactory(15, getArea(areaName)));
        }
        else if (type == ::iAircraftFactory)
        {
            country->getWarEntities()->addInfrastructure(new AircraftDevelopment(15, getArea(areaName)));
        }
        else if (type == ::iGroundCamp)
        {
            country->getWarEntities()->addInfrastructure(new GroundTroopTraining(15, getArea(areaName)));
        }
        else if (type == ::iNavyCamp)
        {
            country->getWarEntities()->addInfrastructure(new NavyTraining(15, getArea(areaName)));
        }
        else if (type == ::iAirforceCamp)
        {
            country->getWarEntities()->addInfrastructure(new AirforceTraining(15, getArea(areaName)));
        }
    }
    else
    {
        cout << "The location was not found" << endl;
    }
}

list<Infrastructure *> WarEngine::getInfrastructureInArea(string areaName, typeOfInfrastructure type)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(areaName);
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (type == temp->getType() && i->getArea()->getName() == areaName)
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Infrastructure *> WarEngine::getAllInfrastructureInArea(string areaName)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(areaName);
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (i->getArea()->getName() == areaName)
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Infrastructure *> WarEngine::getAllFacilitiesInArea(string areaName)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(areaName);
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (temp->getType() != iRoad && temp->getType() != ::iHarbour && temp->getType() != ::iRunway && i->getArea()->getName() == areaName)
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Troops *> WarEngine::getTroopsInArea(string areaName, string countryName)
{
    list<Troops *> result;
    Country *country = getCountry(countryName);
    Area *area = getArea(areaName);
    if (country != nullptr && area != nullptr)
    {
        list<Troops *> troops = country->getWarEntities()->getTroops();
        for (auto t : troops)
        {
            if (t->getLocation() == area)
            {
                result.push_back(t);
            }
        }
    }
    return result;
}

list<Vehicles *> WarEngine::getVehiclesInArea(string areaName, string countryName)
{
    list<Vehicles *> result;
    Country *country = getCountry(countryName);
    Area *area = getArea(areaName);
    if (country != nullptr && area != nullptr)
    {
        list<Vehicles *> troops = country->getWarEntities()->getVehicles();
        for (auto t : troops)
        {
            if (t->getLocation() == area)
            {
                result.push_back(t);
            }
        }
    }
    return result;
}

void WarEngine::addTroops(string areaName, kindOfTroops kind, theTroopTypes type)
{
    Country *country = getCountryFromArea(areaName);
    if (country != nullptr)
    {
        if (country->getNumCitzenGroups() > 0)
        {
            Citizens **citizens = country->getCitizens();
            Citizens *citizen = nullptr;
            for (int i = 0; i < country->getNumCitzenGroups(); i++)
            {
                if (citizens[i]->getStatus() == "Unlisted")
                {
                    citizen = citizens[i];
                    break;
                }
            }
            if (citizens != nullptr)
            {
                citizen->changeStatus();
                list<Infrastructure *> camp;
                if (kind == ::tAirforce)
                {
                    camp = getInfrastructureInArea(areaName, ::iAirforceCamp);
                }
                else if (kind == ::tNavy)
                {
                    camp = getInfrastructureInArea(areaName, ::iNavyCamp);
                }
                else if (kind == ::tGroundTroops)
                {
                    camp = getInfrastructureInArea(areaName, ::iGroundCamp);
                }
                if (!camp.empty() && camp.front() != nullptr)
                {
                    Troops *newTroops = nullptr;
                    if (kind == ::tGroundTroops)
                    {
                        GroundTroopTraining *theCamp = (GroundTroopTraining *)camp.front();
                        newTroops = theCamp->startDrafting(citizen);
                    }
                    else if (kind == ::tNavy)
                    {
                        NavyTraining *theCamp = (NavyTraining *)camp.front();
                        newTroops = theCamp->startDrafting(citizen);
                    }
                    else if (kind == ::tAirforce)
                    {
                        AirforceTraining *theCamp = (AirforceTraining *)camp.front();
                    }
                    if (newTroops != nullptr)
                    {
                        country->getWarEntities()->addTroops(newTroops);
                    }
                    else
                    {
                        cout << "Could not create Troops" << endl;
                    }
                }
                else
                {
                    cout << "There is not a camp to create these troops in this area" << endl;
                }
            }
            else
            {
                cout << "There is no more available citizens in you country" << endl;
            }
        }
        else
        {
            cout << "There is no citizens in you country" << endl;
        }
    }
    else
    {
        cout << "The location was not found" << endl;
    }
}

void WarEngine::addVehicles(string areaName, vehicleType vehicleType)
{
    Country *country = getCountryFromArea(areaName);
    if (country == NULL)
    {
        cout << "The location was not found" << endl;
        return;
    }
    list<Infrastructure *> factory;
    if (vehicleType == ::landVehicle)
    {
        factory = getInfrastructureInArea(areaName, ::iLandFactory);
        if (!factory.empty())
        {
            LandVehicleFactory *fac = (LandVehicleFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(2, 2, 2));
        }
    }
    else if (vehicleType == ::aquaticVehicle)
    {
        factory = getInfrastructureInArea(areaName, ::iAquaticFactory);
        if (!factory.empty())
        {
            AquaticVehicleFactory *fac = (AquaticVehicleFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(2, 2, 2));
        }
    }
    else if (vehicleType == ::aircraftVehicle)
    {
        factory = getInfrastructureInArea(areaName, ::iAircraftFactory);
        if (!factory.empty())
        {
            AircraftFactory *fac = (AircraftFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(2, 2, 2));
        }
    }
}

// TODO: change distance value
void WarEngine::attackArea(string areaName, string countryName)
{
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        Area *area = getArea(areaName);
        if (area != nullptr)
        {
            // check if this is an ally area
            if (area->getControllingCountry() != country)
            {
                Country *enemy = area->getControllingCountry();
                bool isAccessible = false;
                for (auto c : country->getAreas())
                {
                    if (map->isAccessible(c, area))
                    {
                        isAccessible = true;
                    }
                }
                if (isAccessible)
                {
                    moveVehicles(areaName, countryName);
                    moveTroops(areaName, countryName);
                    list<Vehicles *> vehicles = getVehiclesInArea(areaName, countryName);
                    list<Troops *> troops = getTroopsInArea(areaName, countryName);
                    if (!troops.empty())
                    {
                        for (auto t : troops)
                        {
                            t->getAssociatedCitizen()->setStatus(new Fighting());
                        }
                    }
                    list<Vehicles *> enemyVehicles = getVehiclesInArea(areaName, enemy->getName());
                    list<Troops *> enemyTroops = getTroopsInArea(areaName, enemy->getName());
                    if (!enemyTroops.empty())
                    {
                        for (auto t : enemyTroops)
                        {
                            t->getAssociatedCitizen()->setStatus(new Fighting());
                        }
                    }
                    while ((!troops.empty() || !vehicles.empty()) && (!enemyTroops.empty() || !enemyVehicles.empty()))
                    {
                        if (!vehicles.empty())
                        {
                            Vehicles *vehicle = vehicles.front();
                            if (!enemyVehicles.empty())
                            {
                                Vehicles *enemyVehicle = enemyVehicles.front();
                                vehicle->attack(enemyVehicle);
                                if (enemyVehicle->getHP() <= 0)
                                {
                                    enemyVehicles.remove(enemyVehicle);
                                    enemy->getWarEntities()->removeVehicles(enemyVehicle);
                                    enemyVehicle->destroy();
                                }
                            }
                            else
                            {
                                Troops *enemyTroop = enemyTroops.front();
                                vehicle->attack(enemyTroop);
                                if (enemyTroop->getHP() <= 0)
                                {
                                    enemyTroops.remove(enemyTroop);
                                    enemy->getWarEntities()->removeTroops(enemyTroop);
                                    enemy->removeCitizen(enemyTroop->getAssociatedCitizen());
                                    delete enemyTroop->getAssociatedCitizen();
                                    delete enemyTroop;
                                }
                            }
                            if (vehicle->getHP() <= 0)
                            {
                                vehicles.remove(vehicle);
                                country->getWarEntities()->removeVehicles(vehicle);
                                vehicle->destroy();
                            }
                        }
                        else
                        {
                            Troops *troop = troops.front();
                            if (!enemyVehicles.empty())
                            {
                                Vehicles *enemyVehicle = enemyVehicles.front();
                                troop->attack(enemyVehicle);
                                if (enemyVehicle->getHP() <= 0)
                                {
                                    enemyVehicles.remove(enemyVehicle);
                                    enemy->getWarEntities()->removeVehicles(enemyVehicle);
                                    enemyVehicle->destroy();
                                }
                            }
                            else
                            {
                                Troops *enemyTroop = enemyTroops.front();
                                troop->attack(enemyTroop);
                                if (enemyTroop->getHP() <= 0)
                                {
                                    enemyTroops.remove(enemyTroop);
                                    enemy->getWarEntities()->removeTroops(enemyTroop);
                                    enemy->removeCitizen(enemyTroop->getAssociatedCitizen());
                                    delete enemyTroop->getAssociatedCitizen();
                                    delete enemyTroop;
                                }
                            }
                            if (troop->getHP() <= 0)
                            {
                                troops.remove(troop);
                                country->getWarEntities()->removeTroops(troop);
                                country->removeCitizen(troop->getAssociatedCitizen());
                                delete troop->getAssociatedCitizen();
                                delete troop;
                            }
                        }
                    }
                    if (!troops.empty() || !vehicles.empty())
                    {
                        if (!vehicles.empty())
                        {
                            Vehicles *vehicle = vehicles.front();
                            while (!getAllFacilitiesInArea(areaName).empty())
                            {
                                Infrastructure *i = getAllFacilitiesInArea(areaName).front();
                                vehicle->attack(i);
                                enemy->getWarEntities()->removeInfrastructure(i);
                                i->destroy();
                            }
                        }
                        else
                        {
                            Troops *troop = troops.front();
                            while (!getAllFacilitiesInArea(areaName).empty())
                            {
                                Infrastructure *i = getAllFacilitiesInArea(areaName).front();
                                troop->attack(i);
                                enemy->getWarEntities()->removeInfrastructure(i);
                                i->destroy();
                            }
                        }
                        list<Infrastructure *> connections = getAllInfrastructureInArea(areaName);
                        if (!connections.empty())
                        {
                            for (auto c : connections)
                            {
                                enemy->getWarEntities()->removeInfrastructure(c);
                                country->getWarEntities()->addInfrastructure(c);
                            }
                        }
                        enemy->removeArea(getArea(areaName));
                        country->addArea(getArea(areaName));
                        getArea(areaName)->setControllingCountry(country);
                    }
                    else
                    {
                        cout << "The defending side managed to handle the attack" << endl;
                    }
                }
                else
                {
                    cout << "The area is not accessible through safe land, try attacking another area" << endl;
                }
            }
            else
            {
                cout << "This area is already under this county's control" << endl;
            }
        }
        else
        {
            cout << "Area was not found" << endl;
        }
    }
    else
    {
        cout << "Country was not found" << endl;
    }
}

void run(string Mode)
{
    // TODO
    cout << "War mode " + Mode + " activated" << endl;
};

Country WarEngine::pickCountry()
{
    // TODO
    return *this->allCountries.at(0);
};

void WarEngine::removeCountryAt(int index)
{
    this->allCountries.erase(this->allCountries.begin() + index);
};

void WarEngine::setWarMap(WarMap *newMap)
{
    this->map = newMap;
};

void WarEngine::setCountryGroup(vector<Country *> newCountryGroup)
{
    this->allCountries = newCountryGroup;
};

vector<Country *> WarEngine::getCountryGroup()
{
    return this->allCountries;
    ;
};

Memento *WarEngine::createMemento()
{
    // vector<Country*> newCountryGroup;
    // vector<Area*> newWarTheatreGraph;
    // WarMap* newMap = new WarMap();

    // for(int i = 0; i < this->countryGroup.size(); i++){
    //     newCountryGroup.push_back(this->countryGroup.at(i)->clone());
    // }
    // for(int i = 0; i < this->warTheatreGraph.size(); i++){
    //     newWarTheatreGraph.push_back(this->warTheatreGraph.at(i)->clone());
    // }
    // return new Memento(newCountryGroup, newWarTheatreGraph, newMap);
    return nullptr;
};

void WarEngine::reinstateMemento(Memento *memento)
{
    WarPhase *oldphase = memento->warphase;

    this->allCountries = oldphase->getCountryGroup();
    this->map = oldphase->getMap();
};

void WarEngine::printAllies(string countryName)
{
    Country *country = getCountry(countryName);

    vector<Country *> allies = country->getAllies();
    cout << " Allies of " << countryName << ": ";
    for (int i = 0; i < allies.size(); i++)
    {
        cout << allies.at(i)->getName() << ", ";
    }
    cout << endl;
}