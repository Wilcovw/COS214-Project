#ifndef GROUNDTROOPTRAINING_H
#define GROUNDTROOPTRAINING_H
#include "TrainingCamp.h"
/**
 * @brief GroundTroopTraining inherits from TrainingCamp and is used to train troops
 *
 */
class GroundTroopTraining : public TrainingCamp
{
public:
	/**
	 * @brief Construct a new Ground Troop Training object
	 *
	 * @param HP Health of the Ground Troop Training
	 * @param location Where the GroundTroop Training is located
	 */
	GroundTroopTraining(double HP, Area *location);
	/**
	 * @brief Destroy the Ground Troop Training object
	 *
	 */
	virtual ~GroundTroopTraining();
	/**
	 * @brief Starts creating new Ground Troops
	 *
	 * @return Troops*
	 */
	virtual Troops *startDrafting(Citizens *, theTroopTypes);
	/**
	 * @brief Destroy the current Training camp
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