#ifndef NAVY_H
#define NAVY_H
#include "Troops.h"
/**
 * @brief Class for creating Navy troops, child class of Troops
 */
class Navy : public Troops {
    public:
		/**
		 * @brief Construct a new Navy object
		 * 
		 */
        Navy(Area*, TroopType*, Citizens*);
		/**
		 * @brief Destroy the Navy object
		 * 
		 */
        virtual ~Navy();

};

#endif