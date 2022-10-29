
#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "Area.h"

class Infrastructure {
    private:
        double HP;
        Area* location;
    public:
        Infrastructure();
        double getHP();
        void destroy();
        void takeDamage(double);
};

#endif