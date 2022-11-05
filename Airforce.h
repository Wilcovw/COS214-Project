#ifndef AIRFORCE_H
#define AIRFORCE_H
#include "Troops.h"

class Airforce : public Troops {
    public:
		/**
		 * @brief Construct a new Airforce object
		 * 
		 */
        Airforce(Area*, TroopType*, Citizens*);
		/**
		 * @brief Destroy the Airforce object
		 * 
		 */
        virtual ~Airforce();
};

#endif