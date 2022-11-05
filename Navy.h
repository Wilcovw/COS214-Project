#ifndef NAVY_H
#define NAVY_H
#include "Troops.h"

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