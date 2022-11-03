//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_VEHICLES_H
#define FACTORY_AND_OBSERVER_VEHICLES_H
#include <string>
#include "Area.h"

using namespace std;
enum vehicleType {
    landVehicle,
    AquaticVehicle,
    AircraftVehicle
};
class Infrastructure;
class Troops;
class Vehicles
{
private:
    string model;
    double HP;
    double damage;
    double speed;
    int level;
    Area* location;

protected:
    string type;

public:
    /**
     * @brief constructor for vehicle class
     * @param model
     * @param location
     * @param HP
     * @param damage
     * @param speed
     */
    Vehicles(string model, Area* location, double HP, double damage, double speed);
    /**
     *
     * @return the model type of the vehicle
     */
    string getModel();
    /**
    *
    * @return the location of the vehicle
    */
     Area* getLocation();
    /**
    *
    * @return the HP of the vehicle
    */
    double getHP();
    /**
     *
     * @return the damage able to be done by the vehicle
     */
    double getDamage();
    /**
     *
     * @return the speed of the vehicle
     */
    double getSpeed();
    /**
     *
     * @return the level of the vehicle
     */
    int getLevel();
    /**
     *
     * @return a clone of the current vehicle
     */
    Vehicles *clone();
    /**
     *
     * @param n
     * @return an array of size n, which is how many clones should be made
     */
    Vehicles **clone(int n);
    /**
     * @brief method that changes the location of the vehicle to a passed in area
     * @param area
     */
    void changeLocation(Area* area);
    /**
     * @brief method that calls the vehicle's increments level method
     */
    virtual void update();
    /**
     * @brief decreases HP according to the damage done
     * @param dmg
     */
    double takeDamage(double dmg);
    /**
     * increments the vehicle's level
     */
    void incLevel();
    /**
     * @brief outputs the current vehicle's stats, which includes type, model, HP, damage, speed, level
     */
    void print();
    /**
     * @brief takes in the an enemy vehicle that should be attacked as the parameter
     * @param theEnemy
     */
    void attack(Vehicles *theEnemy);
    /**
     * @brief takes in the an enemy troop that should be attacked as the parameter
     * @param theEnemy
     */
    void attack(Troops *theEnemy);
    /**
     * @brief takes in the an enemy building that should be attacked as the parameter
     * @param theEnemy
     */
    void attack(Infrastructure *theEnemy);
    /**
     * @brief Calls class destructor
     */
    void destroy();
};

#endif // FACTORY_AND_OBSERVER_VEHICLES_H