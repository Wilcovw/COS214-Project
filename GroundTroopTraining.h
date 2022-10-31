#ifndef GROUNDTROOPTRAINING_H
#define GROUNDTROOPTRAINING_H
#include "TrainingCamp.h"

class GroundTroopTraining : public TrainingCamp {
    public:
        GroundTroopTraining(double HP, Area* location);
        virtual ~GroundTroopTraining();
        Troops* startDrafting(Citizens*);
        virtual void destroy();
        virtual Infrastructure* clone(Area*);
};

#endif