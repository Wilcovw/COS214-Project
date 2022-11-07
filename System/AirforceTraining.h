#ifndef AIRFORCETRAINING_H
#define AIRFORCETRAINING_H
#include "TrainingCamp.h"

/**
 * @brief AirforceTraining inherits from TrainingCamp and is used to train air force troops
 *
 */
class AirforceTraining : public TrainingCamp
{
public:
	/**
	 * @brief Construct a new Airforce Training object
	 *
	 */
	AirforceTraining(double, Area *);
	/**
	 * @brief Destroy the Airforce Training object
	 *
	 */
	virtual ~AirforceTraining();
	/**
	 * @brief Starts the creation of Troops
	 *
	 * @return Troops*
	 */
	virtual Troops *startDrafting(Citizens *, theTroopTypes);
	/**
	 * @brief Destroys the current Training Camp
	 *
	 */
	virtual void destroy();
	/**
	 * @brief Makes a copy of the current Training Camp
	 *
	 * @return Infrastructure*
	 */
	virtual Infrastructure *clone(Area *);
};

#endif