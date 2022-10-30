#include "Infrastructure.h"

Infrastructure::Infrastructure()
{
}

void Infrastructure::takeDamage(double theDamage)
{
    HP -= theDamage;
}

double Infrastructure::getHP()
{
    return 0;
}
