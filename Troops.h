#ifndef TROOPS_H
#define TROOPS_H
#include "Area.h"
#include "Infrastructure.h"
#include "TroopType.h"
#include "Citizens.h"

class Vehicles;
class Troops {
    protected:
        double HP;
        Area* location;
        TroopType* type;
        Citizens* associatedCitizens;
    public:
        Troops(double,Area* ,TroopType*, Citizens*);
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