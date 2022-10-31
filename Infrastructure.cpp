#include "Infrastructure.h"

Infrastructure::Infrastructure(double hp, Area *area)
{
    location = area;
    HP = hp;
}

Infrastructure::~Infrastructure(){
    delete location;
}

void Infrastructure::takeDamage(double theDamage)
{
    HP -= theDamage;
}

double Infrastructure::getHP()
{
    return 0;
}

void Infrastructure::destroy() {
    delete this;
}

Infrastructure* Infrastructure::clone(){
	return new Infrastructure(HP,location->clone(location->getControllingCountry()));
}
