#ifndef TROOPS_H
#define TROOPS_H
#include "Area.h"
#include "Infrastructure.h"
#include "TroopType.h"
class Vehicles;
class Troops {
    protected:
        double HP;
        Area* location;
        TroopType* type;
    public:
        Troops(double,Area* ,TroopType*);
        virtual ~Troops() {};
        void attack(Troops*);
        void attack(Infrastructure*);
        void attack(Vehicles*);
        double takeDamage(double);
        double getHP();
        Area* getLocation();
        TroopType* getType();
        double getDamage();
        double getMaxHP();
        double getSpeed();
        Troops * clone();
        Troops** clone(int);
};
#endif