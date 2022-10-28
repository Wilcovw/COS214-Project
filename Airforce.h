#ifndef AIRFORCE_H
#define AIRFORCE_H
#include "Troops.h"

class Airforce : public Troops {
    public:
        Airforce(Area*, TroopType*);
        virtual ~Airforce();
};

#endif