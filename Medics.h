#ifndef MEDICS_H
#define MEDICS_H

#include "TroopType.h"

class Medics : public TroopType {
    public:
        Medics();
        virtual ~Medics();
        TroopType* changeType(theTroopTypes);
};

#endif