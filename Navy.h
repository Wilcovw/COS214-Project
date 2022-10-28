#ifndef NAVY_H
#define NAVY_H
#include "Troops.h"

class Navy : public Troops {
    public:
        Navy(Area*, TroopType*);
        virtual ~Navy();
};

#endif