#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "Area.h"

class Infrastructure {
    protected:
        double HP = 0;
        Area* location = nullptr;
    public:
        Infrastructure();
        double getHP();
        void destroy();
        void takeDamage(double);
};

#endif