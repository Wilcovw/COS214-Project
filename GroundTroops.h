#ifndef GROUNDTROOPS_H
#define GROUNDTROOPS_H
#include "Troops.h"

class GroundTroops : public Troops
{
public:
	/**
	 * @brief Construct a new Ground Troops object
	 * 
	 */
	GroundTroops(Area *, TroopType *, Citizens *);
	/**
	 * @brief Destroy the Ground Troops object
	 * 
	 */
	virtual ~GroundTroops();
};

#endif