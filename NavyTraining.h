#ifndef NAVYTRAINING_H
#define NAVYTRAINING_H
#include "TrainingCamp.h"

class NavyTraining : public TrainingCamp
{
public:
	/**
	 * @brief Construct a new Navy Training object
	 * 
	 */
    NavyTraining(double, Area *);
	/**
	 * @brief Destroy the Navy Training object
	 * 
	 */
    virtual ~NavyTraining();
	/**
	 * @brief Starts creating new Navy Troops
	 * 
	 * @param type 
	 * @return Troops* 
	 */
    virtual Troops *startDrafting(Citizens *, theTroopTypes type);
	/**
	 * @brief Destroy the current Training Camp
	 * 
	 */
    virtual void destroy();
	/**
	 * @brief Makes a copy of the current Training camp
	 * 
	 * @return Infrastructure* 
	 */
    virtual Infrastructure *clone(Area *);
};

#endif