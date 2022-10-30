#include "Infrastructure.h"

Infrastructure::Infrastructure(double hp, Area *area)
{
    location = area;
    HP = hp;
}

void Infrastructure::takeDamage(double theDamage)
{
    HP -= theDamage;
}

double Infrastructure::getHP()
{
    return 0;
}
