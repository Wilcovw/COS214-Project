#ifndef TROOPTYPE_H
#define TROOPTYPE_H
#include "WarEngine.h"
#include<iostream>
using namespace std;


class Vehicles;
class TroopType {
    protected:
        double damage;
        double speed;
        double maxHP;
        theTroopTypes type;
    public:
        TroopType(double, double, double);
        virtual ~TroopType();
        double getDamage();
        double getMaxHP();
        double getSpeed();
        void addDamage(double);
        void addMaxHP(double);
        theTroopTypes getType();
        virtual TroopType* changeType(theTroopTypes) = 0;
};

#endif