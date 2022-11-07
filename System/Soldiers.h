#ifndef SOLDIERS_H
#define SOLDIERS_H
#include "TroopType.h"
/**
 * @brief Soldiers are the infantry used in the war. Soldiers inherits from TroopType.
 */
class Soldiers : public TroopType
{
public:
    /**
     * @brief Constructor for this Class. sets Type to Soldier
     */
    Soldiers();
    /**
     * @brief virtual destructor
     */
    virtual ~Soldiers();
    /**
     * @brief Changes the type of the current troop to theTroopTypes, which is passed in
     * @param theType
     * @return TroopType* - the soldier, but with a new type, theType
     */
    TroopType *changeType(theTroopTypes);
};

#endif