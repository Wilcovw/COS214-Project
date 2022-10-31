#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "Area.h"

class Infrastructure {
    protected:
        double HP = 0;
        Area* location = nullptr;
    public:
        Infrastructure();
		Infrastructure(Area* l);
        double getHP();
        void destroy();
        void takeDamage(double);
};

#endif