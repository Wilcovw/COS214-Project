#include "Troops.h"
#include "Infrastructure.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Generals.h"
#include "Medics.h"
#include "Soldiers.h"
#include "TroopType.h"
#include "Vehicles.h"

Troops::Troops(double theHP, Area* theArea, TroopType * theType) {
    HP = theHP;
    location = theArea;
    type = theType;
}

void Troops::attack(Troops * theEnemy) {
    while(HP > 0 && theEnemy->HP > 0) {
        takeDamage(theEnemy->takeDamage(type->getDamage()));
    }
}

void Troops::attack(Infrastructure* theBuilding) {
    while (theBuilding->getHP() > 0) {
        theBuilding->takeDamage(type->getDamage());
    }
}

void Troops::attack(Vehicles* theVehicle) {
    while(HP > 0 && theVehicle->getHP() > 0) {
        takeDamage(theVehicle->takeDamage(type->getDamage()));
    }
}

double Troops::takeDamage(double theDamage) {
    HP -= theDamage;
    if(HP > 0) {
        return type->getDamage();
    } else {
        //TODO: Set functions to change status to dead
    }
    return 0;
}

double Troops::getHP() {
    return HP;
}

double Troops::getDamage() {
    return type->getDamage();
}

Troops * Troops::clone() {
    //Possiblility that by cloning there is not enough citizens. Check with francios how to fix this 
    if(type->getType() == ::theGenerals) {
        return new Troops(this->HP, this->location, new Generals());
    } else if(type->getType() == ::theMedics) {
        return new Troops(this->HP, this->location, new Medics());
    } else if(type->getType() == ::theSoldiers) {
        return new Troops(this->HP, this->location, new Soldiers());
    }
    return nullptr;
}

Troops** Troops::clone(int n) {
    if(n < 1) {
        n = 1;
    }
    Troops** troops = new Troops* [n];
    for(int i = 0; i < n; i++) {
        troops[i] = clone();
    }
    return troops;
}