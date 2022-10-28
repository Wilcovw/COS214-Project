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
	/**
	 * @brief Construct a new Road object
	 * 
	 * @param source 
	 * @param desitination 
	 * @param v 
	 * @param name 
	 */
		Road(Area* source, Area* desitination, double v,string name);
		void destroy();
		~Road();

};

#endif