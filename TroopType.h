#ifndef TROOPTYPE_H
#define TROOPTYPE_H
#include<iostream>
using namespace std;

enum theTroopTypes {
    theGenerals,
    theSoldiers,
    theMedics
};

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