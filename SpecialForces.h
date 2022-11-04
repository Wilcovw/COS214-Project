#ifndef SPECIALFORCE_H
#define SPECIALFORCE_H

#include "TroopType.h"

class SpecialForces : public TroopType {
    public:
        SpecialForces();
        virtual ~SpecialForces();
        TroopType* changeType(theTroopTypes);
};

#endif