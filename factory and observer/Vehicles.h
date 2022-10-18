//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_VEHICLES_H
#define FACTORY_AND_OBSERVER_VEHICLES_H

#include <string>

using namespace std;
class Vehicles {
private:
    string model;
    double HP;
    double damage;
    double speed;
    int level;
protected:
    string type;

public:

    Vehicles(string model, double HP, double damage, double speed);
    string getModel();
    double getHP();
    double getDamage();
    double getSpeed();
    Vehicles* clone();
    Vehicles** clone(int n);
    void print();
    void incLevel();


};


#endif //FACTORY_AND_OBSERVER_VEHICLES_H
