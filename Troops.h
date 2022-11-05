#ifndef TROOPS_H
#define TROOPS_H
#include "WarEngine.h"
#include "TroopType.h"

class Area;
class Vehicles;
class Citizens;
class Troops {
    protected:
        double HP;
        Area* location;
        TroopType* type;
        Citizens* associatedCitizens;
        Troops* clonedTroop;
        kindOfTroops kind;
    public:
        Troops(double, Area*, TroopType*, Citizens*);
        virtual ~Troops();
        void attack(Troops*);
        void attack(Infrastructure*);
        void attack(Vehicles*);
        double takeDamage(double);
        double getHP();
        Area* getLocation();
        void setLocation(Area*);
        TroopType* getType();
        double getDamage();
        double getMaxHP();
        double getSpeed();
        kindOfTroops getKind();
        Troops * clone();
        Troops** clone(int);
        Citizens* getAssociatedCitizen();
        Troops* getClone();
};
#endif