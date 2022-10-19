#include "Area.h"
#include "WarMap.h"
#include <iostream>
using namespace std;
int main(){
	WarMap* graph = new WarMap();
	Area* a1 = new Area("BattleField");
	Area* a2 = new Area("BridgeHead");
	Area* a3 = new Area("Dunkirk");
	Area* a4 = new Area("HackSaw Ridge");
	graph->addArea(a1);
	graph->addArea(a2);
	graph->addArea(a3);
	graph->addArea(a4);

	graph->addEdge(a1, a2, 100, "Duncan Street", "Road");
	cout << a2->getName() << (graph->isAccessible(a1,a2) == true ? " is" : " is not")<<" accessible from " << a1->getName()  << endl;
	cout << a4->getName() << (graph->isAccessible(a3,a4) == true ? " is" : " is not")<<" accessible from " << a4->getName()  << endl;
	return 0;
}