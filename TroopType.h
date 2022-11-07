#ifndef TROOPTYPE_H
#define TROOPTYPE_H
#include "WarEngine.h"
#include<iostream>
using namespace std;


class Vehicles;
/**
 * @brief TroopType is used to set the Troop to a specific type (Generals, Soldiers, SpecialForces). It has these types as sub-classes as well.
 */
class TroopType {
protected:
    /**
     * @brief The TroopType's damage
     */
    double damage;
    /**
     * @brief The TroopType's speed
     */
    double speed;
    /**
     * @brief The TroopType's maxHP
     */
    double maxHP;
    /**
     * @brief The TroopType's type
     */
    theTroopTypes type;
public:
    /**
     * @brief Constructor - sets class' protected variables to passed in parameters
     * @param theDamage
     * @param theMaxHP
     * @param theSpeed
     */
    TroopType(double, double, double);
    /**
     * @brief virtual destructor
     */
    virtual ~TroopType();
    /**
     * @brief returns class' damage
     * @return double - damage
     */
    double getDamage();
    /**
     * @brief returns class' maxHP
     * @return double - maxHP
     */
    double getMaxHP();
    /**
     * @brief returns class' speed
     * @return double - speed
     */
    double getSpeed();
    /**
     * @brief adds theDamage to damage
     * @param theDamage
     */
    void addDamage(double);
    /**
     * @brief adds theMaxHP to maxHP
     * @param theMaxHP
     */
    void addMaxHP(double);
    /**
     * @brief returns the troop type
     * @return theTroopTypes - type
     */
    theTroopTypes getType();
    /**
     * pure virtual function to change type
     * @param theTroopTypes
     * @return 0
     */
    virtual TroopType* changeType(theTroopTypes) = 0;
};

#endif