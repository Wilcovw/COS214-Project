#ifndef TRAININGCAMP_H
#define TRAININGCAMP_H
#include "Troops.h"
#include "Citizens.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Soldiers.h"
#include "Infrastructure.h"

/**
 * @brief TrainingCamp is a type of Infrastructure used to create troops.
 * It has subclasses(GroundTroopTraining, NavyTraining, AirforceTraining) that is used to transform Citizens to Navy, Airforce or GroundTroops
 */
class TrainingCamp : public Infrastructure
{
protected:
    /**
     * @brief a vector of troops
     */
    vector<Troops *> troops;

public:
    /**
     * @brief Constructor - passes parameters to parent class
     * @param theHP
     * @param theLocation
     */
    TrainingCamp(double, Area *);
    /**
     * @brief virtual destructor
     */
    virtual ~TrainingCamp(){};
    /**
     * @brief adds theTroops to the private vector troops
     * @param theTroops
     */
    void addTroop(Troops *theTroops);
    /**
     * @brief searches for theTroops in troops vector and removes it
     * @param theTroops
     * @return true - theTroops has been removed
     * @return false - theTroops was not found in list and has thus not been removed
     */
    bool removeTroop(Troops *theTroops);
    /**
     * @brief returns 2d array of troops
     * @return
     */
    Troops **getTroops();
    /**
     * virtual function
     */
    virtual void destroy() = 0;
    /**
     * @brief virtual clone function that returns nullptr
     * @return Infrastructure* - nullptr
     */
    virtual Infrastructure *clone(Area *) = 0;
    /**
     * @brief virtual function to draft a citizen and make them a troopType
     * @return Troops* - nullptr
     */
    virtual Troops *startDrafting(Citizens *, theTroopTypes) = 0;
};

#endif