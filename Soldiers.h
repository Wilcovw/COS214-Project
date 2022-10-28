#ifndef SOLDIERS_H
#define SOLDIERS_H
#include "TroopType.h"

class Soldiers : public TroopType {
    public:
        Soldiers();
        virtual ~Soldiers();
        TroopType* changeType(theTroopTypes);
};


#endif