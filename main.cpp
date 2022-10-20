#include "Area.h"
#include "WarMap.h"
#include <iostream>
using namespace std;
void isAccessible(Area *a1, Area *a2, WarMap *graph);
void isAccessible(Area *a1, Area *a2, WarMap *graph, string type);
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
	graph->addEdge(a2, a3, 400, "Sydney Harbour", "Harbour");
	graph->addEdge(a3, a4, 400, "Cape Town Harbour", "Harbour");
	isAccessible(a1,a2,graph);
	isAccessible(a3,a4,graph);
	isAccessible(a1,a3,graph);
	isAccessible(a1,a3,graph,"Harbour");
	isAccessible(a2,a3,graph,"Harbour");
	cout << endl;
	isAccessible(a1,a4,graph);
	isAccessible(a2,a4,graph,"Harbour");
	isAccessible(a1,a4,graph,"Harbour");
	return 0;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph){
	cout << a2->getName() << (graph->isAccessible(a1,a2) == true ? " is" : " is not")<<" accessible from " << a1->getName()  << endl;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph, string type){
	cout << a2->getName() << (graph->isAccessible(a1,a2, type) == true ? " is" : " is not")<<" accessible from " << a1->getName() << " via " << type  << endl;
}