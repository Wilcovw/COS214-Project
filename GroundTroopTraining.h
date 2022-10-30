#ifndef GROUNDTROOPTRAINING_H
#define GROUNDTROOPTRAINING_H
#include "TrainingCamp.h"

class GroundTroopTraining : public TrainingCamp {
    public:
        GroundTroopTraining(double HP, Area* location);
        virtual ~GroundTroopTraining();
        void startTraining(Troops*);
        virtual void addTroop(Troops *theTroops);
        virtual bool removeTroop(Troops *theTroops);
        virtual Troops** getTroops();
        Troops* startDrafting(Citizens*);
};

#endif