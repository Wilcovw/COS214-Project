#include "Vehicles.h"
#include "Troops.h"
#include "Area.h"
#include <string>
#include <iostream>
using namespace std;
Vehicles::Vehicles(Area *location, double HP, double damage, double speed)
{
    this->location = location;
    this->HP = HP;
    this->damage = damage;
    this->speed = speed;
    this->level = 1;
}

Area *Vehicles::getLocation()
{
    return location;
}

double Vehicles::getHP()
{
    return HP;
}

double Vehicles::getDamage()
{
    return damage;
}

double Vehicles::getSpeed()
{
    return speed;
}

int Vehicles::getLevel()
{
    return level;
}

// use as: vehicle = vehicle.clone()
Vehicles *Vehicles::clone()
{
    Vehicles *ret = new Vehicles(location, HP, damage, speed);
    ret->type = this->type;
    return ret;
}

/*clones n number of times. Returns array of vehicles*/
Vehicles **Vehicles::clone(int n)
{
    // minimum 1 clone can be made
    if (n < 1)
        n = 1;

    Vehicles **ret = new Vehicles *[n];
    for (int i = 0; i < n; ++i)
    {
        ret[i] = clone();
    }
    return ret;
}

void Vehicles::changeLocation(Area *area)
{
    location = area;
}

double Vehicles::takeDamage(double dmg)
{
    this->HP -= dmg;
    if (HP > 0)
    {
        return getDamage();
    }
    return 0;
}

void Vehicles::incLevel()
{
    double levelMultiplier = (1 / level);
    HP += 5;
    damage += 5;
    speed += 5;
}

void Vehicles::print()
{
    cout << "Type: " << type << "\nHP: "
         << HP << "\ndamage: " << damage << "\nspeed: " << speed
         << "\nlevel: " << level << endl
         << endl;
}

void Vehicles::update()
{
    incLevel();
}

void Vehicles::attack(Vehicles *theEnemy)
{
    while (HP > 0 && theEnemy->HP > 0)
    {
        takeDamage(theEnemy->takeDamage(this->getDamage()));
    }
}

void Vehicles::attack(Troops *theEnemy)
{
    while (HP > 0 && theEnemy->getHP() > 0)
    {
        takeDamage(theEnemy->takeDamage(this->getDamage()));
    }
}

void Vehicles::attack(Infrastructure *theEnemy)
{
    while (theEnemy->getHP() > 0)
    {
        theEnemy->takeDamage(getDamage());
    }
}

Vehicles::~Vehicles() {
    
}

vehicleType Vehicles::getType()
{
    return type;
}