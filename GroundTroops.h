#ifndef GROUNDTROOPS_H
#define GROUNDTROOPS_H
#include "Troops.h"
/**
 * @brief GroundTroops inherits from Troops and represent troops that fignt on land
 *
 */
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