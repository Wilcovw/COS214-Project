#ifndef TROOPS_H
#define TROOPS_H
#include "WarEngine.h"
#include "TroopType.h"

class Area;
class Vehicles;
class Citizens;
/**
 * @brief Troops has three subclasses: GroundTroops, Navy, Airforce. It is the class for the infantry used in the war
 */
class Troops
{
protected:
    /**
     * @brief The health of the Troop
     */
    double HP;
    /**
     * @brief The location the Troop is in
     *
     */
    Area *location;
    /**
     * @brief The type of troop
     *
     */
    TroopType *type;
    /**
     * @brief Stores a Citizen object
     *
     */
    Citizens *associatedCitizens;
    /**
     * @brief The cloned troop
     *
     */
    Troops *clonedTroop;
    /**
     * @brief The kind of troop
     *
     */
    kindOfTroops kind;

public:
    /**
     * @brief Constructor - sets private variables to passed in parameters
     */
    Troops(double, Area *, TroopType *, Citizens *);
    /**
     * @brief virtual destructor
     */
    virtual ~Troops();
    /**
     * @brief attacks the passed in parameter - Troops*
     */
    void attack(Troops *);
    /**
     * @brief attacks the passed in parameter - Infrastructure*
     */
    void attack(Infrastructure *);
    /**
     * @brief attacks the passed in parameter - Vehicles*
     */
    void attack(Vehicles *);
    /**
     * @brief HP lessens by theDamage
     * @param theDamage
     * @return double - the new HP
     */
    double takeDamage(double);
    /**
     * @brief returns class' HP
     * @return double - HP
     */
    double getHP();
    /**
     * @brief returns class' location
     * @return Area* - location
     */
    Area *getLocation();
    /**
     * @brief sets the class' location to theLocation
     * @param theLocation
     */
    void setLocation(Area *);
    /**
     * @brief returns class' type
     * @return TroopType* - type
     */
    TroopType *getType();
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
     * @brief returns kind of troop
     * @return kondOfTroops - kind
     */
    kindOfTroops getKind();
    /**
     * @brief returns a clone of this class
     * @return Troops* - this
     */
    Troops *clone();
    /**
     * @brief returns class' associatedCitizens
     * @return Citizens* - associatedCitizens
     */
    Citizens *getAssociatedCitizen();
    /**
     * @brief releases the associatedCitizens
     */
    void releaseAssociatedCitizen();
    /**
     * @brief returns class' clone
     * @return Troops* - clonedTroop
     */
    Troops *getClone();
};
#endif