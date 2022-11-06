#ifndef FACTORY_AND_OBSERVER_VEHICLES_H
#define FACTORY_AND_OBSERVER_VEHICLES_H
#include <string>
#include "Infrastructure.h"
#include "WarEngine.h"

using namespace std;

class Area;
class Troops;
/**
 * @brief This is the class for vehicles to be constructed by factories. It has 3 subclasses (Aircraft, AquaticVehicles, LandVehicles)
 */
class Vehicles
{
private:
	/**
	 * @brief The health of the Vechile
	 * 
	 */
    double HP;
	/**
	 * @brief The damgae the Vechile will inflict
	 * 
	 */
    double damage;
	/**
	 * @brief How fast the vechile is
	 * 
	 */
    double speed;
	/**
	 * @brief The location which the Vechile is located
	 * 
	 */
    Area *location;

protected:
	/**
	 * @brief The type of vechile it is
	 * 
	 */
    vehicleType type;

public:
    /**
     * @brief constructor for vehicle class
     * @param location
     * @param HP
     * @param damage
     * @param speed
     */
    Vehicles(Area *location, double HP, double damage, double speed);
    /**
     *
     * @return the location of the vehicle
     */
    Area *getLocation();
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
     * @return a clone of the current vehicle
     */
    Vehicles *clone(Area* newArea);
    /**
     *
     * @param n
     * @return an array of size n, which is how many clones should be made
     */
    Vehicles **clone(int n, Area* newArea);
    /**
     * @brief method that changes the location of the vehicle to a passed in area
     * @param area
     */
    void changeLocation(Area *area);
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
     * increments the vehicle's stats
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
    virtual ~Vehicles();
    /**
     * @brief returns the Vehicle's type
     * @return vehicleType - type
     */
    vehicleType getType();
};

#endif // FACTORY_AND_OBSERVER_VEHICLES_H