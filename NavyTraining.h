#ifndef NAVYTRAINING_H
#define NAVYTRAINING_H
#include "TrainingCamp.h"

class NavyTraining : public TrainingCamp {
    public:
        NavyTraining(double, Area*);
        virtual ~NavyTraining();;
        Troops* startDrafting(Citizens*);
        virtual void destroy();
        virtual Infrastructure* clone(Area*);
};

#endif