#ifndef AIRFORCETRAINING_H
#define AIRFORCETRAINING_H
#include "TrainingCamp.h"

class AirforceTraining : public TrainingCamp {
    public:
        AirforceTraining(double, Area*);
        virtual ~AirforceTraining();
        Troops* startDrafting(Citizens*);
        virtual void destroy();
        virtual Infrastructure* clone(Area*);
};

#endif