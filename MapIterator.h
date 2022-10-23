#ifndef MapIterator_H
#define MapIterator_H
#include "Area.h"
class MapIterator
{
private:
	/* data */
public:
	MapIterator(/* args */);
	~MapIterator();
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
};

#endif