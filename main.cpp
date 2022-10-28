#include "Area.h"
#include "WarMap.h"
#include "AreaIterator.h"
#include <iostream>
using namespace std;
void isAccessible(Area *a1, Area *a2, WarMap *graph);
void isAccessible(Area *a1, Area *a2, WarMap *graph, string type);
int main()
{
	WarMap *graph = new WarMap();
	Area *a1 = new Area("BattleField");
	Area *a2 = new Area("BridgeHead");
	Area *a3 = new Area("Dunkirk");
	Area *a4 = new Area("HackSaw Ridge");
	Area *a5 = new Area("Frombrok");
	Area *a6 = new Area("Luban");
	Area *a7 = new Area("Goldap");
	graph->addArea(a1);
	graph->addArea(a2);
	graph->addArea(a3);
	graph->addArea(a4);
	graph->addArea(a5);
	graph->addArea(a6);

	graph->addEdge(a1, a2, 100, "Duncan Street", "Road");
	graph->addEdge(a2, a3, 400, "Sydney Harbour", "Harbour");
	graph->addEdge(a3, a4, 400, "Cape Town Harbour", "Harbour");
	graph->addEdge(a4, a1, 350, "OR Tambo", "Runway");
	graph->addEdge(a4, a5, 350, "Durban International Airport", "Runway");
	// graph->addEdge(a5, a4, 180, "Cape Town International Airport", "Runway");
	isAccessible(a1, a2, graph);
	isAccessible(a3, a4, graph);
	isAccessible(a1, a3, graph);
	isAccessible(a1, a4, graph);
	// From a4 to a1
	isAccessible(a4, a1, graph);
	// From a5 to a1
	isAccessible(a1, a5, graph);
	cout << endl;

	isAccessible(a2, a4, graph, "Harbour");
	isAccessible(a1, a4, graph, "Harbour");
	isAccessible(a1, a3, graph, "Harbour");
	isAccessible(a2, a3, graph, "Harbour");
	// From a4 to a1 via Runway
	isAccessible(a4, a1, graph, "Runway");
	// From a4 to a1 via Harbour
	isAccessible(a5, a1, graph, "Harbour");

	list<Area *> path = graph->shortestPath(a1, a5);
	cout << endl
		 << "Shortest path from " << a1->getName() << " to " << a5->getName() << endl
		 << endl;
	cout << "Size: " << path.size() << endl;
	for (auto a : path)
	{
		cout << a->getName() << endl;
	}
	// cout << endl
	// 	 << "Print all the areas:" << endl;
	// AreaIterator *areaIter = graph->createAreaIterator();
	// areaIter->first();
	// while (areaIter->isDone() == false)
	// {
	// 	Area *currentArea = areaIter->currentItem();
	// 	cout << currentArea->getName() << endl;

	// 	areaIter->next();
	// }

	// cout << endl
	// 	 << "Print all the Edges:" << endl;
	// EdgeIterator *edgeIter = graph->createEdgeIterator();
	// edgeIter->first();
	// while (edgeIter->isDone() == false)
	// {
	// 	Edge *currentEdge = edgeIter->currentItem();
	// 	cout << currentEdge->getName() << endl;

	// 	edgeIter->next();
	// }
	return 0;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph)
{
	cout << a2->getName() << (graph->isAccessible(a1, a2) == true ? " is" : " is not") << " accessible from " << a1->getName() << endl;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph, string type)
{
	cout << a2->getName() << (graph->isAccessible(a1, a2, type) == true ? " is" : " is not") << " accessible from " << a1->getName() << " via " << type << endl;
}