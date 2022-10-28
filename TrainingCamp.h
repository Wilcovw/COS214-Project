#ifndef TRAININGCAMP_H
#define TRAININGCAMP_H
#include "Troops.cpp"


class TrainingCamp {
    protected:
        Troops ** troops;
        int numTroops;
    public:
        TrainingCamp();
        void addTroop(Troops* theTroops);
        bool removeTroop(Troops* theTroops);
};

#endif