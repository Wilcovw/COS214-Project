#ifndef GROUNDTROOPTRAINING_H
#define GROUNDTROOPTRAINING_H
#include "TrainingCamp.h"

class GroundTroopTraining : public TrainingCamp {
    public:
        GroundTroopTraining();
        virtual ~GroundTroopTraining();
        void startTraining(Troops*);
};

#endif