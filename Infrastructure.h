#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "WarEngine.h"
class Area;
class Infrastructure
{
protected:
    double HP;
    Area *location;
    typeOfInfrastructure type;
public:

    /**
     * @brief Construct a new Infrastructure object
     *
     * @param area
     * @param hp
     */
    Infrastructure(double hp, Area *area);
    /**
     * @brief destructor
     */
    virtual ~Infrastructure(){};
    /**
     * @brief Returns class private variable HP
     * @return HP
     */
    double getHP();
    /**
     * @brief destructor
     */
    virtual void destroy();
    /**
     * @brief Decreases HP of this class by the amount of the parameter passed in
     * @param theDamage
     */
    void takeDamage(double theDamage);
    /**
     *
     * @param newArea
     * @return
     */
    virtual Infrastructure *clone(Area *newArea);
    /**
     * @brief Get the Area object
     *
     * @return Area*
     */
    Area *getArea();
	/**
	 * @brief Get the Type OF Infrastructure
	 * 
	 * @return typeOfInfrastructure 
	 */
    typeOfInfrastructure getType();
};

#endif