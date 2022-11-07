#ifndef GENERALS_H
#define GENERALS_H
#include "TroopType.h"
/**
 * @brief A type of Troop with a lot of HP but little damage
 *
 */
class Generals : public TroopType
{
public:
	/**
	 * @brief Construct a new Generals object
	 *
	 */
	Generals();
	/**
	 * @brief Destroy the Generals object
	 *
	 */
	virtual ~Generals();
	/**
	 * @brief Change the type of the Generals object
	 *
	 * @return TroopType*
	 */
	TroopType *changeType(theTroopTypes);
};
#endif