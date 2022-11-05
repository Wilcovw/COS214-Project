#ifndef SOLDIERS_H
#define SOLDIERS_H
#include "TroopType.h"

class Soldiers : public TroopType
{
public:
    /**
     * @brief
     */
    Soldiers();
    virtual ~Soldiers();
    TroopType *changeType(theTroopTypes);
};

#endif