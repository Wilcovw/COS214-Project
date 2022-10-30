
#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "Area.h"

class Infrastructure {
    private:
        double HP;
        Area* location;
    public:
        /**
         * @brief default constructor
         */
        Infrastructure();
        /**
         * @brief Returns class private variable HP
         * @return HP
         */
        double getHP();
        /**
         * @brief destructor
         */
        void destroy();
        /**
         * @brief Decreases HP of this class by the amount of the parameter passed in
         * @param theDamage
         */
        void takeDamage(double theDamage);
};

#endif