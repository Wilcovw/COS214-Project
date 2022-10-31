#include "Vehicles.h"
#include "Troops.h"
#include <string>
#include <iostream>
using namespace std;
Vehicles::Vehicles(string model, double HP, double damage, double speed) {
    this->model = model;
    this->HP = HP;
    this->damage=damage;
    this->speed=speed;
    this->level=1;

}

string Vehicles::getModel() {
    return model;
}

double Vehicles::getHP() {
    return HP;
}

double Vehicles::getDamage() {
    return damage;
}

double Vehicles::getSpeed() {
    return speed;
}

int Vehicles::getLevel() {
    return level;
}

//use as: vehicle = vehicle.clone()
Vehicles *Vehicles::clone() {
    Vehicles* ret = new Vehicles(model, HP, damage, speed);
    ret->type = this->type;
    return ret;
}

/*clones n number of times. Returns array of vehicles*/
Vehicles **Vehicles::clone(int n) {
    //minimum 1 clone can be made
    if(n<1)
        n=1;

    Vehicles **ret = new Vehicles*[n];
    for (int i = 0; i < n; ++i) {
        ret[i] = clone();

    }
    return ret;
}

double Vehicles::takeDamage(double dmg) {
    this->HP-=dmg;
    if(HP > 0) {
        return getDamage();
    } else {
        destroy();
    }
    return 0;
}

void Vehicles::incLevel() {
    double levelMultiplier = (1/level);
    HP += levelMultiplier*HP;
    damage += levelMultiplier*damage;
    speed += levelMultiplier*speed;
    level++;

}

void Vehicles::print() {
    cout << "Type: " << type << "\nmodel: " << model + "\nHP: "
         << HP << "\ndamage: " << damage << "\nspeed: " << speed
         << "\nlevel: " << level << endl << endl;
}

void Vehicles::update() {
    incLevel();
}


void Vehicles::attack(Vehicles *theEnemy) {
    while(HP > 0 && theEnemy->HP > 0) {
        takeDamage(theEnemy->takeDamage(this->getDamage()));
    }
}

void Vehicles::attack(Troops *theEnemy) {
    while(HP > 0 && theEnemy->getHP() > 0) {
        takeDamage(theEnemy->takeDamage(this->getDamage()));
    }
}

void Vehicles::destroy() {
    delete this;
}