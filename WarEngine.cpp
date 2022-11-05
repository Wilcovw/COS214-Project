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
#include "SpecialForces.h"
#include "Troops.h"
#include "LandVehicles.h"
#include "AquaticVehicleFactory.h"
#include "AircraftFactory.h"
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

void newWarPhase()
{
}

void reverseWarPhase()
{
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
    if (getRelationship(relationshipName) == nullptr && communication != nullptr)
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
    cout << "Country: " << countryName << " was not found" << endl;
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
    cout << "The country with area: " << areaName << " was not found." << endl;
    return nullptr;
}

void WarEngine::addArea(string areaName, string countryName)
{
    if (getCountry(countryName) != nullptr)
    {
        Area *newArea = new Area(areaName, getCountry(countryName));
        map->addArea(newArea);
    }
};

Area *WarEngine::getArea(string areaName)
{
    if (map->getArea(areaName) != nullptr)
    {
        return map->getArea(areaName);
    }
    else
    {
        cout << "Area " << areaName << " was not found" << endl;
        return nullptr;
    }
}

list<Area *> WarEngine::getTravelPath(Vehicles *vehicle, Area *destination)
{
    list<Area *> result;
    Area *source = vehicle->getLocation();
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

list<Area *> WarEngine::getTravelPath(Troops *troops, Area *destination)
{
    list<Area *> result;
    if (troops != nullptr)
    {
        if (destination != nullptr)
        {
            list<Area *> path;
            if (troops->getKind() == ::tGroundTroops)
            {
                result = map->shortestPath(troops->getLocation(), destination, "Road");
            }
            else if (troops->getKind() == ::tAirforce)
            {
                result = map->shortestPath(troops->getLocation(), destination, "Runway");
            }
            else if (troops->getKind() == ::tNavy)
            {
                result = map->shortestPath(troops->getLocation(), destination, "Harbour");
            }
        }
    }
    return result;
}

double WarEngine::getTravelDistance(Vehicles *vehicle, Area *destination)
{
    Area *source = vehicle->getLocation();
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

double WarEngine::getTravelDistance(Troops *troops, Area *destination)
{
    double distance = -1;
    if (troops != nullptr)
    {
        if (destination != nullptr)
        {
            list<Area *> path;
            if (troops->getKind() == ::tGroundTroops)
            {
                path = map->shortestPath(troops->getLocation(), destination, "Road");
            }
            else if (troops->getKind() == ::tAirforce)
            {
                path = map->shortestPath(troops->getLocation(), destination, "Runway");
            }
            else if (troops->getKind() == ::tNavy)
            {
                path = map->shortestPath(troops->getLocation(), destination, "Harbour");
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

void WarEngine::moveVehicles(Area *destination, Country *country, int maxDistance)
{
    if (country != nullptr)
    {
        if (destination != nullptr)
        {
            list<Vehicles *> vehicles = country->getWarEntities()->getVehicles();
            if (!vehicles.empty())
            {
                for (auto e : vehicles)
                {
                    if (getTravelDistance(e, destination) <= maxDistance)
                    {
                        e->changeLocation(destination);
                    }
                }
            }
        }
    }
}

// TODO: change distance value
void WarEngine::moveVehicles(string areaName, string countryName)
{
    moveVehicles(getArea(areaName), getCountry(countryName), 200);
}

void WarEngine::moveTroops(Area *destination, Country *country, int maxDistance)
{
    if (country != nullptr)
    {
        if (destination != nullptr)
        {
            list<Troops *> troops = country->getWarEntities()->getTroops();
            if (!troops.empty())
            {
                for (auto t : troops)
                {
                    if (getTravelDistance(t, destination) <= maxDistance)
                    {
                        t->setLocation(destination);
                    }
                }
            }
        }
    }
}

// TODO: change distance value
void WarEngine::moveTroops(string areaName, string countryName)
{
    moveTroops(getArea(areaName), getCountry(countryName), 100);
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
            if (getInfrastructureInArea(getArea(sourceName), type).empty())
            {
                theHarbour = new Harbour(getArea(sourceName), 3);
                country->getWarEntities()->addInfrastructure(theHarbour);
            }
            else
            {
                theHarbour = (Harbour *)getInfrastructureInArea(getArea(sourceName), type).front();
            }
            if (getInfrastructureInArea(getArea(destinationName), type).empty())
            {
                theOtherHarbour = new Harbour(getArea(destinationName), 3);
                destination->getWarEntities()->addInfrastructure(theOtherHarbour);
            }
            else
            {
                theOtherHarbour = (Harbour *)getInfrastructureInArea(getArea(destinationName), type).front();
            }
            theHarbour->addConnection(getArea(destinationName), distance, theOtherHarbour);
        }
        else if (type == ::iRunway)
        {
            Runway *theRunway;
            Runway *theOtherRunway;
            if (getInfrastructureInArea(getArea(sourceName), type).empty())
            {
                theRunway = new Runway(getArea(sourceName), 3);
                country->getWarEntities()->addInfrastructure(theRunway);
            }
            else
            {
                theRunway = (Runway *)getInfrastructureInArea(getArea(sourceName), type).front();
            }
            if (getInfrastructureInArea(getArea(destinationName), type).empty())
            {
                theOtherRunway = new Runway(getArea(destinationName), 3);
                destination->getWarEntities()->addInfrastructure(theOtherRunway);
            }
            else
            {
                theOtherRunway = (Runway *)getInfrastructureInArea(getArea(destinationName), type).front();
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
            country->getWarEntities()->addInfrastructure(new Harbour(getArea(areaName), 100));
        }
        else if (type == ::iRunway)
        {
            country->getWarEntities()->addInfrastructure(new Runway(getArea(areaName), 100));
        }
        else if (type == ::iLandDevelopment)
        {
            country->getWarEntities()->addInfrastructure(new LandVehicleDevelopment(800, getArea(areaName)));
        }
        else if (type == ::iAquaticDevelopment)
        {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleDevelopment(800, getArea(areaName)));
        }
        else if (type == ::iAircraftDevelopment)
        {
            country->getWarEntities()->addInfrastructure(new AircraftDevelopment(800, getArea(areaName)));
        }
        else if (type == ::iLandFactory)
        {
            country->getWarEntities()->addInfrastructure(new LandVehicleFactory(1200, getArea(areaName)));
        }
        else if (type == ::iAquaticFactory)
        {
            country->getWarEntities()->addInfrastructure(new AquaticVehicleFactory(1200, getArea(areaName)));
        }
        else if (type == ::iAircraftFactory)
        {
            country->getWarEntities()->addInfrastructure(new AircraftFactory(1200, getArea(areaName)));
        }
        else if (type == ::iGroundCamp)
        {
            country->getWarEntities()->addInfrastructure(new GroundTroopTraining(1000, getArea(areaName)));
        }
        else if (type == ::iNavyCamp)
        {
            country->getWarEntities()->addInfrastructure(new NavyTraining(1000, getArea(areaName)));
        }
        else if (type == ::iAirforceCamp)
        {
            country->getWarEntities()->addInfrastructure(new AirforceTraining(1000, getArea(areaName)));
        }
    }
    else
    {
        cout << "The location was not found" << endl;
    }
}

list<Infrastructure *> WarEngine::getInfrastructureInArea(Area *area, typeOfInfrastructure type)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(area->getName());
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (type == temp->getType() && i->getArea()->getName() == area->getName())
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Infrastructure *> WarEngine::getAllInfrastructureInArea(Area *area)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(area->getName());
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (i->getArea()->getName() == area->getName())
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Infrastructure *> WarEngine::getAllFacilitiesInArea(Area *area)
{
    list<Infrastructure *> output;
    Country *country = getCountryFromArea(area->getName());
    if (country != nullptr && !country->getWarEntities()->getInfrastructure().empty())
    {
        list<Infrastructure *> allInfrastructure = country->getWarEntities()->getInfrastructure();
        for (auto i : allInfrastructure)
        {
            Infrastructure *temp = i;
            if (temp->getType() != iRoad && temp->getType() != ::iHarbour && temp->getType() != ::iRunway && i->getArea()->getName() == area->getName())
            {
                output.push_back(temp);
            }
        }
    }
    return output;
}

list<Troops *> WarEngine::getTroopsInArea(Area *area, Country *country)
{
    list<Troops *> result;
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

list<Vehicles *> WarEngine::getVehiclesInArea(Area *area, Country *country)
{
    list<Vehicles *> result;
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
                if (citizens[i] != nullptr && citizens[i]->getStatus() == "Unlisted")
                {
                    citizen = citizens[i];
                    break;
                }
            }
            if (citizen != nullptr)
            {
                citizen->changeStatus();
                list<Infrastructure *> camp;
                if (kind == ::tAirforce)
                {
                    camp = getInfrastructureInArea(getArea(areaName), ::iAirforceCamp);
                }
                else if (kind == ::tNavy)
                {
                    camp = getInfrastructureInArea(getArea(areaName), ::iNavyCamp);
                }
                else if (kind == ::tGroundTroops)
                {
                    camp = getInfrastructureInArea(getArea(areaName), ::iGroundCamp);
                }
                if (!camp.empty() && camp.front() != nullptr)
                {
                    Troops *newTroops = nullptr;
                    if (kind == ::tGroundTroops)
                    {
                        GroundTroopTraining *theCamp = (GroundTroopTraining *)camp.front();
                        newTroops = theCamp->startDrafting(citizen, type);
                    }
                    else if (kind == ::tNavy)
                    {
                        NavyTraining *theCamp = (NavyTraining *)camp.front();
                        newTroops = theCamp->startDrafting(citizen, type);
                    }
                    else if (kind == ::tAirforce)
                    {
                        AirforceTraining *theCamp = (AirforceTraining *)camp.front();
                        newTroops = theCamp->startDrafting(citizen, type);
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
                cout << "There are no more available citizens in " << country->getName() << endl;
            }
        }
        else
        {
            cout << "There are no citizens in your country" << endl;
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
    if (country == nullptr)
    {
        cout << "The location was not found" << endl;
        return;
    }
    list<Infrastructure *> factory;
    if (vehicleType == ::landVehicle)
    {
        factory = getInfrastructureInArea(getArea(areaName), ::iLandFactory);
        if (!factory.empty())
        {
            LandVehicleFactory *fac = (LandVehicleFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(40, 40, 60));
        }
        else
        {
            cout << "There is no factory in " << areaName << " to create a land vehicle" << endl;
        }
    }
    else if (vehicleType == ::aquaticVehicle)
    {
        factory = getInfrastructureInArea(getArea(areaName), ::iAquaticFactory);
        if (!factory.empty())
        {
            AquaticVehicleFactory *fac = (AquaticVehicleFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(50, 20, 50));
        }
        else
        {
            cout << "There is no factory in " << areaName << " to create an aquatic vehicle" << endl;
        }
    }
    else if (vehicleType == ::aircraftVehicle)
    {
        factory = getInfrastructureInArea(getArea(areaName), ::iAircraftFactory);
        if (!factory.empty())
        {
            AircraftFactory *fac = (AircraftFactory *)factory.front();
            country->getWarEntities()->addVehicles(fac->createVehicle(30, 50, 900));
        }
        else
        {
            cout << "There is no factory in " << areaName << " to create a aircraft vehicle" << endl;
        }
    }
}

int WarEngine::getUnlistedCitizens(string countryName)
{
    int n = 0;
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        Citizens **citizens = country->getCitizens();
        if (citizens != nullptr)
        {
        }
    }
    return n;
}

void WarEngine::printCountryStatus(string countryName)
{
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << countryName << " Status Report: " << endl;
        cout << country->getParent()->print() << endl;

        cout << country->printAreas();
        int unlisted = 0;
        int dead = 0;

        int landGenerals = 0;
        int navyGenerals = 0;
        int airForceGenerals = 0;
        int landSoldiers = 0;
        int navySoldiers = 0;
        int airForceSoldiers = 0;
        int landSpecialForces = 0;
        int navySpecialForces = 0;
        int airForceSpecialForces = 0;
        for (int i = 0; i < country->getNumCitzenGroups(); i++)
        {
            string status = country->getCitizens()[i]->getStatus();
            if (status.compare("Unlisted") == 0)
            {
                unlisted++;
            }
            else if (status.compare("Dead") == 0)
            {
                dead++;
            }
        }
        for (auto t : country->getWarEntities()->getTroops())
        {
            if (t->getKind() == ::tGroundTroops)
            {
                if (t->getType()->getType() == ::theGenerals)
                {
                    landGenerals++;
                }
                else if (t->getType()->getType() == ::theSoldiers)
                {
                    landSoldiers++;
                }
                else if (t->getType()->getType() == ::theSpecialForces)
                {
                    landSpecialForces++;
                }
            }
            else if (t->getKind() == ::tNavy)
            {
                if (t->getType()->getType() == ::theGenerals)
                {
                    navyGenerals++;
                }
                else if (t->getType()->getType() == ::theSoldiers)
                {
                    navySoldiers++;
                }
                else if (t->getType()->getType() == ::theSpecialForces)
                {
                    navySpecialForces++;
                }
            }

            else if (t->getKind() == ::tAirforce)
            {
                if (t->getType()->getType() == ::theGenerals)
                {
                    airForceGenerals++;
                }
                else if (t->getType()->getType() == ::theSoldiers)
                {
                    airForceSoldiers++;
                }
                else if (t->getType()->getType() == ::theSpecialForces)
                {
                    airForceSpecialForces++;
                }
            }
        }

        cout << "\nNumber of groups/battalions of citizens/troops :" << endl;
        cout << "Unlisted citizens: \t\t" << unlisted
             << endl;
        cout << "Land generals: \t\t\t" << landGenerals << endl;
        cout << "Navy generals: \t\t\t" << navyGenerals << endl;
        cout << "Air force generals: \t\t" << airForceGenerals << endl;
        cout << "Land special forces: \t\t" << landSpecialForces << endl;
        cout << "Navy special forces: \t\t" << navySpecialForces << endl;
        cout << "Air force special forces: \t" << airForceSpecialForces << endl;
        cout << "Land soldiers: \t\t\t" << landSoldiers << endl;
        cout << "Navy soldiers: \t\t\t" << navySoldiers << endl;
        cout << "Air force soldiers: \t\t" << airForceSoldiers << endl;
        cout << "Dead citizens: \t\t\t" << dead << endl;

        int landVehicles = 0;
        int navyVehicles = 0;
        int airForceVehicles = 0;
        for (auto v : country->getWarEntities()->getVehicles())
        {
            if (v->getType() == ::landVehicle)
            {
                landVehicles++;
            }
            else if (v->getType() == ::aquaticVehicle)
            {
                navyVehicles++;
            }
            else if (v->getType() == ::aircraftVehicle)
            {
                airForceVehicles++;
            }
        }
        cout << "\nNumber of different types of vehicles: " << endl;
        cout << "Land vehicles: \t\t\t" << landVehicles << endl;
        cout << "Navy vehicles: \t\t\t" << navyVehicles << endl;
        cout << "Air Force vehicles: \t\t" << airForceVehicles << endl;
        int roads = 0;
        int harbours = 0;
        int runways = 0;
        int landDevelopments = 0;
        int navyDevelopments = 0;
        int airForceDevelopments = 0;
        int landFactory = 0;
        int navyFactory = 0;
        int airForceFactory = 0;
        int landCamps = 0;
        int navyCamps = 0;
        int airForceCamps = 0;
        for (auto i : country->getWarEntities()->getInfrastructure())
        {
            if (i->getType() == ::iRoad)
            {
                roads++;
            }
            else if (i->getType() == ::iHarbour)
            {
                harbours++;
            }
            else if (i->getType() == ::iRunway)
            {
                runways++;
            }
            else if (i->getType() == ::iLandDevelopment)
            {
                landDevelopments++;
            }
            else if (i->getType() == ::iAquaticDevelopment)
            {
                navyDevelopments++;
            }
            else if (i->getType() == ::iAircraftDevelopment)
            {
                airForceDevelopments++;
            }
            else if (i->getType() == ::iLandFactory)
            {
                landFactory++;
            }
            else if (i->getType() == ::iAquaticFactory)
            {
                navyFactory++;
            }
            else if (i->getType() == ::iAircraftFactory)
            {
                airForceFactory++;
            }
            else if (i->getType() == ::iGroundCamp)
            {
                landCamps++;
            }
            else if (i->getType() == ::iNavyCamp)
            {
                navyCamps++;
            }
            else if (i->getType() == ::iAirforceCamp)
            {
                airForceCamps++;
            }
        }
        cout << "\nInfrastructure: " << endl;

        cout << "Number of roads/harbours/runways under " << country->getName() << "'s control: " << endl;
        cout << "Number of roads: \t\t\t\t" << roads << endl;
        cout << "Number of harbours: \t\t\t\t" << harbours << endl;
        cout << "Number of runways: \t\t\t\t" << runways << endl;

        cout << "Number of research and development centres: " << endl;
        cout << "Number of land research centres: \t\t" << landDevelopments << endl;
        cout << "Number of navy research centres: \t\t" << navyDevelopments << endl;
        cout << "Number of air force research centres: \t\t" << airForceDevelopments << endl;

        cout << "Number of vehicle factories: " << endl;
        cout << "Number of land vehicle factories: \t\t" << landFactory << endl;
        cout << "Number of navy vehicle factories: \t\t" << navyFactory << endl;
        cout << "Number of air force vehicle factories: \t\t" << airForceFactory << endl;

        cout << "Number of troop training camps: " << endl;
        cout << "Number of land troop training camps: \t\t" << landCamps << endl;
        cout << "Number of navy troop training camps: \t\t" << navyCamps << endl;
        cout << "Number of air force troop training camps: \t" << airForceCamps << endl;

        cout << "-----------------------------------------------------------" << endl;
    }
}

void WarEngine::printAreaStatus(string areaName)
{
    Area *area = getArea(areaName);
    Country *country = getCountryFromArea(areaName);
    if (area != nullptr && country != nullptr)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << areaName << " Status Report: " << endl;
        int landGenerals = 0;
        int navyGenerals = 0;
        int airForceGenerals = 0;
        int landSoldiers = 0;
        int navySoldiers = 0;
        int airForceSoldiers = 0;
        int landSpecialForces = 0;
        int navySpecialForces = 0;
        int airForceSpecialForces = 0;
        for (auto t : country->getWarEntities()->getTroops())
        {
            if (t->getLocation() == area)
            {
                if (t->getKind() == ::tGroundTroops)
                {
                    if (t->getType()->getType() == ::theGenerals)
                    {
                        landGenerals++;
                    }
                    else if (t->getType()->getType() == ::theSoldiers)
                    {
                        landSoldiers++;
                    }
                    else if (t->getType()->getType() == ::theSpecialForces)
                    {
                        landSpecialForces++;
                    }
                }
                else if (t->getKind() == ::tNavy)
                {
                    if (t->getType()->getType() == ::theGenerals)
                    {
                        navyGenerals++;
                    }
                    else if (t->getType()->getType() == ::theSoldiers)
                    {
                        navySoldiers++;
                    }
                    else if (t->getType()->getType() == ::theSpecialForces)
                    {
                        navySpecialForces++;
                    }
                }

                else if (t->getKind() == ::tAirforce)
                {
                    if (t->getType()->getType() == ::theGenerals)
                    {
                        airForceGenerals++;
                    }
                    else if (t->getType()->getType() == ::theSoldiers)
                    {
                        airForceSoldiers++;
                    }
                    else if (t->getType()->getType() == ::theSpecialForces)
                    {
                        airForceSpecialForces++;
                    }
                }
            }
        }

        cout << "\nNumber of groups/battalions of citizens/troops :" << endl;
        cout << "Land generals: \t\t\t" << landGenerals << endl;
        cout << "Navy generals: \t\t\t" << navyGenerals << endl;
        cout << "Air force generals: \t\t" << airForceGenerals << endl;
        cout << "Land special forces: \t\t" << landSpecialForces << endl;
        cout << "Navy special forces: \t\t" << navySpecialForces << endl;
        cout << "Air force special forces: \t" << airForceSpecialForces << endl;
        cout << "Land soldiers: \t\t\t" << landSoldiers << endl;
        cout << "Navy soldiers: \t\t\t" << navySoldiers << endl;
        cout << "Air force soldiers: \t\t" << airForceSoldiers << endl;

        int landVehicles = 0;
        int navyVehicles = 0;
        int airForceVehicles = 0;
        for (auto v : country->getWarEntities()->getVehicles())
        {
            if (v->getLocation() == area)
            {
                if (v->getType() == ::landVehicle)
                {
                    landVehicles++;
                }
                else if (v->getType() == ::aquaticVehicle)
                {
                    navyVehicles++;
                }
                else if (v->getType() == ::aircraftVehicle)
                {
                    airForceVehicles++;
                }
            }
        }
        cout << "\nNumber of different types of vehicles: " << endl;
        cout << "Land vehicles: \t\t\t" << landVehicles << endl;
        cout << "Navy vehicles: \t\t\t" << navyVehicles << endl;
        cout << "Air Force vehicles: \t\t" << airForceVehicles << endl;
        int roads = 0;
        int harbours = 0;
        int runways = 0;
        int landDevelopments = 0;
        int navyDevelopments = 0;
        int airForceDevelopments = 0;
        int landFactory = 0;
        int navyFactory = 0;
        int airForceFactory = 0;
        int landCamps = 0;
        int navyCamps = 0;
        int airForceCamps = 0;
        for (auto i : country->getWarEntities()->getInfrastructure())
        {
            if (i->getArea() == area)
            {
                if (i->getType() == ::iLandDevelopment)
                {
                    landDevelopments++;
                }
                else if (i->getType() == ::iAquaticDevelopment)
                {
                    navyDevelopments++;
                }
                else if (i->getType() == ::iAircraftDevelopment)
                {
                    airForceDevelopments++;
                }
                else if (i->getType() == ::iLandFactory)
                {
                    landFactory++;
                }
                else if (i->getType() == ::iAquaticFactory)
                {
                    navyFactory++;
                }
                else if (i->getType() == ::iAircraftFactory)
                {
                    airForceFactory++;
                }
                else if (i->getType() == ::iGroundCamp)
                {
                    landCamps++;
                }
                else if (i->getType() == ::iNavyCamp)
                {
                    navyCamps++;
                }
                else if (i->getType() == ::iAirforceCamp)
                {
                    airForceCamps++;
                }
            }
        }

        list<Edge *> edges = area->getEdges();
        if (!edges.empty())
        {
            for (auto e : edges)
            {
                if (e->getType() == "Road")
                {
                    roads++;
                }
                else if (e->getType() == "Harbour")
                {
                    harbours++;
                }
                else if (e->getType() == "Runway")
                {
                    runways++;
                }
            }
        }

        cout << "\nInfrastructure: " << endl;

        cout << "Number of roads/harbours/runways under " << country->getName() << "'s control: " << endl;
        cout << "Number of roads: \t\t\t\t" << roads << endl;
        cout << "Number of harbours: \t\t\t\t" << harbours << endl;
        cout << "Number of runways: \t\t\t\t" << runways << endl;

        cout << "Number of research and development centres: " << endl;
        cout << "Number of land research centres: \t\t" << landDevelopments << endl;
        cout << "Number of navy research centres: \t\t" << navyDevelopments << endl;
        cout << "Number of air force research centres: \t\t" << airForceDevelopments << endl;

        cout << "Number of vehicle factories: " << endl;
        cout << "Number of land vehicle factories: \t\t" << landFactory << endl;
        cout << "Number of navy vehicle factories: \t\t" << navyFactory << endl;
        cout << "Number of air force vehicle factories: \t\t" << airForceFactory << endl;

        cout << "Number of troop training camps: " << endl;
        cout << "Number of land troop training camps: \t\t" << landCamps << endl;
        cout << "Number of navy troop training camps: \t\t" << navyCamps << endl;
        cout << "Number of air force troop training camps: \t" << airForceCamps << endl;

        cout << "-----------------------------------------------------------" << endl;
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
            if (area->getControllingCountry() != country && country->getParent() != getCountryFromArea(areaName)->getParent())
            {
                Country *enemy = area->getControllingCountry();
                bool isAccessible = false;
                for (auto a : country->getAreas())
                {
                    if (map->isAccessible(a, area))
                    {
                        isAccessible = true;
                        break;
                    }
                }
                if (isAccessible)

                {
                    moveVehicles(areaName, countryName);
                    moveTroops(areaName, countryName);
                    list<Vehicles *> vehicles = getVehiclesInArea(getArea(areaName), getCountry(countryName));
                    list<Troops *> troops = getTroopsInArea(getArea(areaName), getCountry(countryName));
                    for (auto c : country->getAllies())
                    {
                        moveVehicles(areaName, c->getName());
                        for (auto v : getVehiclesInArea(getArea(areaName), c))
                        {
                            vehicles.push_back(v);
                        }
                        moveTroops(areaName, c->getName());
                        for (auto t : getTroopsInArea(getArea(areaName), c))
                        {
                            troops.push_back(t);
                        }
                    }

                    if (!troops.empty())
                    {
                        for (auto t : troops)
                        {
                            t->getAssociatedCitizen()->setStatus(new Fighting());
                        }
                    }

                    list<Vehicles *> enemyVehicles = getVehiclesInArea(getArea(areaName), enemy);
                    list<Troops *> enemyTroops = getTroopsInArea(getArea(areaName), enemy);
                    for (auto c : enemy->getAllies())
                    {
                        moveVehicles(getArea(areaName), c, 100);
                        for (auto v : getVehiclesInArea(getArea(areaName), c))
                        {
                            enemyVehicles.push_back(v);
                        }
                        moveTroops(getArea(areaName), c, 50);
                        for (auto t : getTroopsInArea(getArea(areaName), c))
                        {
                            enemyTroops.push_back(t);
                        }
                    }

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
                                    enemyTroop->getAssociatedCitizen()->die();
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
                                    enemyTroop->getAssociatedCitizen()->die();
                                    delete enemyTroop;
                                }
                            }

                            if (troop->getHP() <= 0)
                            {
                                troops.remove(troop);
                                country->getWarEntities()->removeTroops(troop);
                                troop->getAssociatedCitizen()->die();
                                delete troop;
                            }
                        }
                    }
                    if (!troops.empty() || !vehicles.empty())
                    {
                        if (!vehicles.empty())
                        {
                            Vehicles *vehicle = vehicles.front();
                            while (!getAllFacilitiesInArea(getArea(areaName)).empty())
                            {
                                Infrastructure *i = getAllFacilitiesInArea(getArea(areaName)).front();
                                vehicle->attack(i);
                                enemy->getWarEntities()->removeInfrastructure(i);
                                i->destroy();
                            }
                        }
                        else
                        {
                            Troops *troop = troops.front();
                            while (!getAllFacilitiesInArea(getArea(areaName)).empty())
                            {
                                Infrastructure *i = getAllFacilitiesInArea(getArea(areaName)).front();
                                troop->attack(i);
                                enemy->getWarEntities()->removeInfrastructure(i);
                                i->destroy();
                            }
                        }
                        list<Infrastructure *> connections = getAllInfrastructureInArea(getArea(areaName));
                        if (!connections.empty())
                        {
                            for (auto c : connections)
                            {
                                enemy->getWarEntities()->removeInfrastructure(c);
                                country->getWarEntities()->addInfrastructure(c);
                            }
                        }

                        enemy->removeArea(
                            getArea(areaName));
                        country->addArea(getArea(areaName));

                        getArea(areaName)->setControllingCountry(country);
                        if (!troops.empty())
                        {
                            for (auto t : troops)
                            {
                                t->getAssociatedCitizen()->setStatus(new Stationed());
                            }
                        }
                        cout << "The area was successfully overthrown" << endl;

                        distributeTroopsAndVehicles(countryName);
                        for (auto c : country->getAllies())
                        {
                            distributeTroopsAndVehicles(c->getName());
                        }

                        distributeTroopsAndVehicles(enemy->getName());
                        for (auto c : enemy->getAllies())
                        {
                            distributeTroopsAndVehicles(c->getName());
                        }

                        if (enemy->getAreas().empty())
                        {
                            cout << enemy->getName() << " has no more Areas to control and has successfully been defeated" << endl;
                            allCountries.remove(enemy);
                            Relationship *relationship = (Relationship *)enemy->getParent();
                            allCountries.remove(enemy);
                            delete enemy;
                            if (relationship->getRelationships().empty())
                            {
                                delete relationship;
                            }
                        }
                    }
                    else
                    {
                        if (!enemyTroops.empty())
                        {
                            for (auto t : enemyTroops)
                            {
                                t->getAssociatedCitizen()->setStatus(new Stationed());
                            }
                        }
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
                cout << "This area is not in enemy's control" << endl;
            }
        }
    }
}

void WarEngine::distributeTroopsAndVehicles(string countryName)
{
    Country *country = getCountry(countryName);
    if (country != nullptr)
    {
        list<Troops *> troops = country->getWarEntities()->getTroops();
        list<Vehicles *> vehicles = country->getWarEntities()->getVehicles();
        list<Area *> areas = country->getAreas();
        while (!troops.empty() || !vehicles.empty())
        {
            for (auto a : areas)
            {
                if (!troops.empty())
                {
                    Troops *troop = troops.front();
                    if (troop->getKind() == ::tNavy && !getInfrastructureInArea(a, ::iHarbour).empty())
                    {
                        troops.remove(troops.front());
                        troop->setLocation(a);
                    }
                    else if (troop->getKind() == ::tAirforce && !getInfrastructureInArea(a, ::iRunway).empty())
                    {
                        troops.remove(troops.front());
                        troop->setLocation(a);
                    }
                    else if (troop->getKind() == ::tGroundTroops)
                    {
                        troops.remove(troops.front());
                        troop->setLocation(a);
                    }
                }
                if (!vehicles.empty())
                {
                    Vehicles *vehicle = vehicles.front();
                    if (vehicle->getType() == ::aquaticVehicle && !getInfrastructureInArea(a, ::iHarbour).empty())
                    {
                        vehicles.remove(vehicle);
                        vehicle->changeLocation(a);
                    }
                    else if (vehicle->getType() == ::aircraftVehicle && !getInfrastructureInArea(a, ::iRunway).empty())
                    {
                        vehicles.remove(vehicle);
                        vehicle->changeLocation(a);
                    }
                    else if (vehicle->getType() == ::landVehicle)
                    {
                        vehicles.remove(vehicle);
                        vehicle->changeLocation(a);
                    }
                }
            }
        }
    }
}

bool WarEngine::countryStillExists(string countryName)
{
    Country *country = getCountry(countryName);
    if (country == nullptr)
    {
        return false;
    }
    return true;
}

void WarEngine::upgradeVehiclesInArea(vehicleType type, string areaName)
{
    Country *country = getCountryFromArea(areaName);
    Area *area = getArea(areaName);
    if (country == nullptr)
    {
        cout << "The location was not found" << endl;
        return;
    }
    list<Infrastructure *> facility;
    list<Vehicles *> vehicles;
    if (type == ::landVehicle)
    {
        facility = getInfrastructureInArea(getArea(areaName), ::iLandDevelopment);
        vehicles = getVehiclesInArea(area, country);
        if (!facility.empty())
        {
            if (!vehicles.empty())
            {
                LandVehicleDevelopment *fac = (LandVehicleDevelopment *)facility.front();
                for (auto v : vehicles)
                {
                    fac->addToList(v);
                    fac->startDeveloping();
                }
            }
            else
            {
                cout << "There is no vehicles in " << areaName << " to upgrade " << endl;
            }
        }
        else
        {
            cout << "There is no research facility in " << areaName << " to upgrade a land vehicle" << endl;
        }
    }
    else if (type == ::aquaticVehicle)
    {
        facility = getInfrastructureInArea(getArea(areaName), ::iAquaticDevelopment);
        vehicles = getVehiclesInArea(area, country);
        if (!facility.empty())
        {
            if (!vehicles.empty())
            {
                AquaticVehicleDevelopment *fac = (AquaticVehicleDevelopment *)facility.front();
                for (auto v : vehicles)
                {
                    fac->addToList(v);
                    fac->startDeveloping();
                }
            }
            else
            {
                cout << "There is no vehicles in " << areaName << " to upgrade " << endl;
            }
        }
        else
        {
            cout << "There is no research facility in " << areaName << " to upgrade an aquatic vehicle" << endl;
        }
    }

    else if (type == ::aircraftVehicle)
    {
        facility = getInfrastructureInArea(getArea(areaName), ::iAircraftDevelopment);
        vehicles = getVehiclesInArea(area, country);
        if (!facility.empty())
        {
            if (!vehicles.empty())
            {
                AircraftDevelopment *fac = (AircraftDevelopment *)facility.front();
                for (auto v : vehicles)
                {
                    fac->addToList(v);
                    fac->startDeveloping();
                }
            }
            else
            {
                cout << "There is no vehicles in " << areaName << " to upgrade " << endl;
            }
        }
        else
        {
            cout << "There is no research facility in " << areaName << " to upgrade a aircraft vehicle" << endl;
        }
    }
}

void run(string Mode)
{
    // TODO
    cout << "War mode " + Mode + " activated" << endl;
};

void WarEngine::setWarMap(WarMap *newMap)
{
    this->map = newMap;
};

void WarEngine::setCountryGroup(list<Country *> newCountryGroup)
{
    this->allCountries = newCountryGroup;
};

list<Country *> WarEngine::getCountryGroup()
{
    return this->allCountries;
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

    // this->allCountries = oldphase->getCountryGroup();
    this->map = oldphase->getMap();
};
