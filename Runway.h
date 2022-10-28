#ifndef Runway_H
#define Runway_H
#include <list>
#include "Edge.h"
#include "Area.h"
#include <string>
using namespace std;
class Runway
{
private:
	string name;
	list<Edge*> flights;
public:
	Runway(Area *destination, double v,string name);
	bool addConnection(Area* destination, double v,string name);
	void destroy();
	~Runway();
};

#endif