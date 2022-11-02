#ifndef INFASTRUCTURE_H
#define INFASTRUCTURE_H
#include "Area.h"

enum typeOfInfrastructure {
    iRoad,
    iHarbour,
    iRunway,
    iLandDevlopment,
    iAquaticDevelopment,
    iAircraftDevelopment,
    iLandFactory,
    iAquaticFactory,
    iAircraftFactory,
    iGroundCamp,
    iNavyCamp,
    iAirforceCamp
};

class Infrastructure
{
protected:
    double HP;
    Area *location;
    typeOfInfrastructure type;
public:
    /**
     * @brief default constructor
     */
    // Infrastructure(){};
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

    typeOfInfrastructure getType();
};

#endif