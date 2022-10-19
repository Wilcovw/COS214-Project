#ifndef WarMap_H
#define WarMap_H
#include <list>
#include <string>
#include "Area.h"
#include <iterator>
using namespace std;

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
};

#endif