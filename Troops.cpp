#include "Troops.h"
#include "TroopType.h"
#include "Infrastructure.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Generals.h"
#include "Medics.h"
#include "Soldiers.h"
#include "Vehicles.h"

Troops::Troops(double theHP, Area *theArea, TroopType *theType, Citizens *theCitizen)
{
    associatedCitizens = theCitizen;
    HP = theHP;
    location = theArea;
    type = theType;
}

Troops::~Troops() {
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

kindOfTroops Troops::getKind() { 
    return kind;
}

void Troops::setLocation(Area* theLocation) {
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
    if(type->getType() == ::theGenerals) {
        clonedTroop = new Troops(this->HP, this->location, new Generals(), citizens);
    } else if(type->getType() == ::theMedics) {
        clonedTroop = new Troops(this->HP, this->location, new Medics(), citizens);
    } else if(type->getType() == ::theSoldiers) {
        clonedTroop = new Troops(this->HP, this->location, new Soldiers(), citizens);
    }
    return clonedTroop;
}

Troops **Troops::clone(int n)
{
    if (n < 1)
    {
        n = 1;
    }
    Troops **troops = new Troops *[n];
    for (int i = 0; i < n; i++)
    {
        troops[i] = clone();
    }
    return troops;
}

Citizens* Troops::getAssociatedCitizen(){
    return associatedCitizens;
}

Troops* Troops::getClone() {
    return clonedTroop;
}