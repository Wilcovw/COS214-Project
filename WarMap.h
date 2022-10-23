#ifndef WarMap_H
#define WarMap_H
#include <list>
#include <string>
#include "Area.h"
#include "AreaIterator.h"
#include <iterator>
using namespace std;

class AreaIterator;
//The Graph
class WarMap{
	private:
		list<Area*> areasWT;
	public:
		WarMap();
		~WarMap();
		Area* getArea(string name);
		bool isAccessible(Area* source,  Area* destination);
		bool isAccessible(Area* source,  Area* destination, string type);
		bool addEdge(Area* source,  Area* destination, double distance, string name, string type);
		bool addArea(Area *a);
		void reset();
		list<Area*> getAreaList();
		AreaIterator* createAreaIterator();
		list<Area *>::iterator begin();
		list<Area *>::iterator end();
};

#endif