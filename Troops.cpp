#include "Troops.h"
#include "TroopType.h"
#include "Infrastructure.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Generals.h"
#include "SpecialForces.h"
#include "Soldiers.h"
#include "Vehicles.h"
#include "Area.h"
#include "TroopType.h"
#include "Citizens.h"

Troops::Troops(double theHP, Area *theArea, TroopType *theType, Citizens *theCitizen)
{
    associatedCitizens = theCitizen;
    HP = theHP;
    location = theArea;
    type = theType;
}

Troops::~Troops()
{
    delete type;
}

void Troops::attack(Troops *theEnemy)
{
    while (HP > 0 && theEnemy->HP > 0)
    {
        takeDamage(theEnemy->takeDamage(type->getDamage()));
    }
}

void Troops::attack(Infrastructure *theBuilding)
{
    while (theBuilding->getHP() > 0)
    {
        theBuilding->takeDamage(type->getDamage());
    }
}

void Troops::attack(Vehicles *theVehicle)
{
    while (HP > 0 && theVehicle->getHP() > 0)
    {
        takeDamage(theVehicle->takeDamage(type->getDamage()));
    }
}

double Troops::takeDamage(double theDamage)
{
    HP -= theDamage;
    if (HP > 0)
    {
        return type->getDamage();
    }
    else
    {
        associatedCitizens->die();
    }
    return 0;
}

double Troops::getHP()
{
    return HP;
}

Area *Troops::getLocation()
{
    return this->location;
}

TroopType *Troops::getType()
{
    return type;
}

double Troops::getMaxHP()
{
    return type->getMaxHP();
}

double Troops::getSpeed()
{
    return type->getSpeed();
}

double Troops::getDamage()
{
    return type->getDamage();
}

kindOfTroops Troops::getKind()
{
    return this->kind;
}

void Troops::setLocation(Area *theLocation)
{
    location = theLocation;
}

Troops *Troops::clone()
{
    Citizens *citizens = new Citizens();
    if (associatedCitizens->getStatus() == "Enlisted")
    {
        citizens->setStatus(new Enlisted());
    }
    else if (associatedCitizens->getStatus() == "Stationed")
    {
        citizens->setStatus(new Stationed());
    }
    else if (associatedCitizens->getStatus() == "Fighting")
    {
        citizens->setStatus(new Fighting());
    }
    clonedTroop = nullptr;
    if (type->getType() == ::theGenerals)
    {
        if (kind == ::tNavy)
        {
            clonedTroop = new Navy(this->location, new Generals(), citizens);
        }
        else if (kind == ::tGroundTroops)
        {
            clonedTroop = new GroundTroops(this->location, new Generals(), citizens);
        }
        else if (kind == ::tAirforce)
        {
            clonedTroop = new Airforce(this->location, new Generals(), citizens);
        }
    }
    else if (type->getType() == ::theSpecialForces)
    {
        if (kind == ::tNavy)
        {
            clonedTroop = new Navy(this->location, new SpecialForces(), citizens);
        }
        else if (kind == ::tGroundTroops)
        {
            clonedTroop = new GroundTroops(this->location, new SpecialForces(), citizens);
        }
        else if (kind == ::tAirforce)
        {
            clonedTroop = new Airforce(this->location, new SpecialForces(), citizens);
        }
    }
    else if (type->getType() == ::theSoldiers)
    {
        if (kind == ::tNavy)
        {
            clonedTroop = new Navy(this->location, new Soldiers(), citizens);
        }
        else if (kind == ::tGroundTroops)
        {
            clonedTroop = new GroundTroops(this->location, new Soldiers(), citizens);
        }
        else if (kind == ::tAirforce)
        {
            clonedTroop = new Airforce(this->location, new Soldiers(), citizens);
        }
    }
    return clonedTroop;
}

Citizens *Troops::getAssociatedCitizen()
{
    return associatedCitizens;
}

void Troops::releaseAssociatedCitizen()
{
    associatedCitizens = nullptr;
}

Troops *Troops::getClone()
{
    return clonedTroop;
}