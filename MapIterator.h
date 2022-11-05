#ifndef MapIterator_H
#define MapIterator_H
#include "Area.h"
class MapIterator
{
private:
	/* data */
public:
	/**
	 * @brief Constructor for map iterator
	 * 
	 */
	MapIterator(/* args */);
	/**
	 * @brief Destructor of Map Iterator object
	 * 
	 */
	~MapIterator();
	/**
	 * @brief Derived class should reset the iteration
	 * 
	 */
	virtual void first() = 0;
	/**
	 * @brief Derived class should get the next element in the iteration
	 * 
	 */
	virtual void next() = 0;
	/**
	 * @brief Checks if the iteration is done, and returns the result
	 * 
	 * @return true , if the iteration is done
	 * @return false , if the iteration is not done
	 */
	virtual bool isDone() = 0;
};

#endif