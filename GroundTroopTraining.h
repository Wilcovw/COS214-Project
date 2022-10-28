#ifndef GROUNDTROOPTRAINING_H
#define GROUNDTROOPTRAINING_H
#include "TrainingCamp.cpp"

class GroundTroopTraining : public TrainingCamp {
    public:
        GroundTroopTraining();
        void startTraining(Troops*);
};

#endif