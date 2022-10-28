#ifndef GENERALS_H
#define GENERALS_H
#include "TroopType.h"

class Generals : public TroopType {
    public:
        Generals();
        virtual ~Generals();
        TroopType* changeType(theTroopTypes);
};
#endif