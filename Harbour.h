#ifndef Harbour_H
#define Harbour_H
#include <list>
#include "Edge.h"
#include "Area.h"
#include <string>
using namespace std;
class Harbour
{
private:
	string name;
	list<Edge*> connectedHarbours;
public:
	Harbour(Area *destination);
	bool addConnection(Area* destination, double v,string name);
	void destroy();
	~Harbour();
};

#endif

