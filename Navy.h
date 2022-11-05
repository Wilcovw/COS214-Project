#ifndef NAVY_H
#define NAVY_H
#include "Troops.h"

class Navy : public Troops {
public:
    /**
     * @brief Constructor for Navy type troops. Sets kind to Navy.
     */
    Navy(Area*, TroopType*, Citizens*);
    /**
     * @brief virtual destructor for class
     */
    virtual ~Navy();

};

#endif