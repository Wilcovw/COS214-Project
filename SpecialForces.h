#ifndef SPECIALFORCE_H
#define SPECIALFORCE_H

#include "TroopType.h"

/**
 * @brief SpecialForces are the infantry used in the war. SpecialForces inherits from TroopType.
 */
class SpecialForces : public TroopType {
public:
    /**
     * @brief Constructor for this Class. sets Type to Soldier
     */
    SpecialForces();
    /**
     * @brief virtual destructor
     */
    virtual ~SpecialForces();
    /**
     * @brief Changes the type of the current troop to theTroopTypes, which is passed in
     * @param theType
     * @return TroopType* - the soldier, but with a new type, theType
     */
    TroopType* changeType(theTroopTypes);
};

#endif