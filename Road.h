#ifndef Road_H
#define Road_H
#include "Edge.h"
#include "Area.h"
#include <string>
using namespace std;
class Road{
	private:
		string name;
		Edge *theRoad;
	public:
		Road(Area* source, Area* desitination, double v,string name);
		void destroy();
		~Road();

};

#endif