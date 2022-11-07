#ifndef TROOPTYPE_CPP
#define TROOPTYPE_CPP
#include "TroopType.h"
#include "Generals.h"
#include "SpecialForces.h"
#include "Soldiers.h"
#include "Vehicles.h"

TroopType::TroopType(double theDamage, double theMaxHP, double theSpeed) {
    damage = theDamage;
    maxHP = theMaxHP;
    speed = theSpeed;
}


TroopType::~TroopType() {
    
}

double TroopType::getDamage(){
    return damage;
}

double TroopType::getMaxHP() {
    return maxHP;
}

double TroopType::getSpeed() {
    return speed;
}

void TroopType::addDamage(double theDamage) {
    damage += theDamage;
}   

void TroopType::addMaxHP(double theMaxHP) {
    maxHP += theMaxHP;
}

theTroopTypes TroopType::getType() {
    return type;
}

#endif