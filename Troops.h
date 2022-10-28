#ifndef TROOPS_H
#define TROOPS_H
#include "Area.h"
#include "Infrastructure.h"
#include "Vehicles.h"
#include "TroopType.h"

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
        Troops * clone();
        Troops** clone(int);
};
#endif