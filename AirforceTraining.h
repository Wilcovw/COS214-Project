#ifndef AIRFORCETRAINING_H
#define AIRFORCETRAINING_H
#include "TrainingCamp.h"

class AirforceTraining : public TrainingCamp {
    public:
        AirforceTraining(double, Area*);
        virtual ~AirforceTraining();
        virtual void addTroop(Troops *theTroops);
        virtual bool removeTroop(Troops *theTroops);
        virtual Troops** getTroops();
        Troops* startDrafting(Citizens*);
        void startTraining();
};

#endif