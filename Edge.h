#ifndef Edge_H
#define Edge_H
#include "Area.h"
#include <string>

using namespace std;
class Area;
class Edge
{
private:
	Area* source = nullptr;
	Area* destination = nullptr;
	double distance = 0;
	string name;
	string type;
public:
	Edge(double v,string name, string type,Area* s, Area* d);
	~Edge();
	Area* getSource();
	Area* getDestination();
	string getType();
	string getDescription();
	string getName();
	double getDistance();
	
	
};

#endif
