#ifndef NAVYTRAINING_H
#define NAVYTRAINING_H
#include "TrainingCamp.h"

class NavyTraining : public TrainingCamp {
    public:
        NavyTraining(double, Area*);
        virtual ~NavyTraining();
        virtual void addTroop(Troops *theTroops);
        virtual bool removeTroop(Troops *theTroops);
        virtual Troops** getTroops();
        void startTraining();
        Troops* startDrafting(Citizens*);
};

#endif