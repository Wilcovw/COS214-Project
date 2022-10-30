#include "Area.h"
#include "WarMap.h"
#include "AreaIterator.h"
#include "CommunicationBroadcast.h"
#include "Relationship.h"
#include "Country.h"
#include <iostream>
using namespace std;
void isAccessible(Area *a1, Area *a2, WarMap *graph);
void isAccessible(Area *a1, Area *a2, WarMap *graph, string type);
int main(){
	WarMap * warMap = new WarMap();
	Communication *tele = new CommunicationBroadcast();
	Country *germany = new Country("Germany", tele);
	Country *france = new Country("France", tele);
	Country *spain = new Country("Spain", tele);
	
	//Areas in Germnay
	Area *berlin = new Area("Berlin", germany);
	//Areas in France
	Area *paris = new Area("Paris", france);
	//Areas in Spain
	Area *madrid = new Area("Madrid",spain);

	
	Country *italy = new Country("Italy", tele);
	Country *poland = new Country("Poland", tele);
	Country *austria = new Country("Austria", tele);
	Country *hungary = new Country("Hungary", tele);
	//Areas in Italy
	Area *rome = new Area("Rome",italy);
	//Areas in Poland
	Area *warsaw = new Area("Warsaw",poland);
	//Areas in Austria
	Area *vienna = new Area("Vienna",austria);
	//Areas in Hungary
	Area *budapest = new Area("Budapest",hungary);

	//Add all Area's to the graph
	warMap->addArea(berlin);
	warMap->addArea(paris);
	warMap->addArea(madrid);
	warMap->addArea(rome);
	warMap->addArea(warsaw);
	warMap->addArea(vienna);
	warMap->addArea(budapest);

	//delete warMap and Areas in it
	delete warMap;
	//Delete all countries
	delete germany;
	delete france;
	delete spain;
	delete italy;
	delete poland;
	delete austria;
	delete hungary;



	return 0;
}
// int main()
// {
// 	// setup and initialisation for all testing

// 	Communication *tele = new CommunicationBroadcast();
// 	AssociatedCountries *countriesAtWar = new Relationship("Countries in the war", tele);
// 	AssociatedCountries *allies = new Relationship("Allies", tele);
// 	AssociatedCountries *axis = new Relationship("Axis", tele);
// 	Country *germany = new Country("Germany", tele);
// 	Country *england = new Country("England", tele);
// 	Citizens **citizens = germany->getCitizens();

// 	WarMap *graph = new WarMap();
// 	Area *a1 = new Area("BattleField", germany);
// 	Area *a2 = new Area("BridgeHead", germany);
// 	Area *a3 = new Area("Dunkirk", england);
// 	Area *a4 = new Area("HackSaw Ridge", england);
// 	Area *a5 = new Area("Frombrok", england);
// 	Area *a6 = new Area("Luban", germany);
// 	Area *a7 = new Area("Goldap", germany);

// 	graph->addArea(a1);
// 	graph->addArea(a2);
// 	graph->addArea(a3);
// 	graph->addArea(a4);
// 	graph->addArea(a5);
// 	graph->addArea(a6);
// 	graph->addArea(a7);

// 	graph->addEdge(a1, a2, 100, "Duncan Street", "Road");
// 	graph->addEdge(a2, a3, 400, "Sydney Harbour", "Harbour");
// 	graph->addEdge(a3, a4, 400, "Cape Town Harbour", "Harbour");
// 	graph->addEdge(a4, a1, 350, "OR Tambo", "Runway");
// 	graph->addEdge(a4, a5, 350, "Durban International Airport", "Runway");
// 	graph->addEdge(a5, a4, 180, "Cape Town International Airport", "Runway");

// 	// testing changing citizen state
// 	{
// 		for (int i = 0; i < 5; i++)
// 		{
// 			citizens[i]->changeStatus();
// 			if (i == 3)
// 			{
// 				citizens[i]->die();
// 			}
// 		}

// 		for (int i = 0; i < germany->getNumCitzenGroups(); i++)
// 		{
// 			cout << "Group " << i << " citizens current state: " << citizens[i]->getStatus() << endl;
// 		}
// 	}
// 	// testing if areas store controlling countries correctly and the other way around
// 	{
// 		std::cout << "The country that controls area a1 is : " << a1->getControllingCountry()->getName() << std::endl;
// 		a1->setControllingCountry(england);
// 		std::cout << "The country that controls area a1 is : " << a1->getControllingCountry()->getName() << std::endl;
// 		std::cout << england->printAreas();
// 	}
// 	// testing the accessibility of areas in the graph
// 	{
// 		isAccessible(a1, a2, graph);
// 		isAccessible(a3, a4, graph);
// 		isAccessible(a1, a3, graph);
// 		isAccessible(a1, a4, graph);
// 		// From a4 to a1
// 		isAccessible(a4, a1, graph);
// 		// From a5 to a1

// 		isAccessible(a1, a5, graph);

// 		cout << endl;

// 		isAccessible(a2, a4, graph, "Harbour");
// 		isAccessible(a1, a4, graph, "Harbour");
// 		isAccessible(a1, a3, graph, "Harbour");
// 		isAccessible(a2, a3, graph, "Harbour");
// 		// From a4 to a1 via Runway
// 		isAccessible(a4, a1, graph, "Runway");
// 		// From a4 to a1 via Harbour
// 		isAccessible(a5, a1, graph, "Harbour");
// 	}
// 	// testing shortest path algortihm

// 	list<Area *> path = graph->shortestPath(a1, a5);
// 	cout << endl
// 		 << "Shortest path from " << a1->getName() << " to " << a5->getName() << endl
// 		 << endl;
// 	cout << "Size: " << path.size() << endl;
// 	cout << "Hello" << endl;
// 	for (auto a : path)
// 	{
// 		cout << a->getName() << endl;
// 	}
// 	cout << endl
// 		 << "Print all the areas:" << endl;
// 	AreaIterator *areaIter = graph->createAreaIterator();
// 	areaIter->first();
// 	while (areaIter->isDone() == false)
// 	{
// 		Area *currentArea = areaIter->currentItem();
// 		cout << currentArea->getName() << endl;

// 		areaIter->next();
// 	}

// 	// printing out all edges in graph

// 	cout << endl
// 		 << "Print all the Edges:" << endl;
// 	EdgeIterator *edgeIter = graph->createEdgeIterator();
// 	edgeIter->first();
// 	while (edgeIter->isDone() == false)
// 	{
// 		Edge *currentEdge = edgeIter->currentItem();
// 		cout << currentEdge->getName() << endl;

// 		edgeIter->next();
// 	}

// 	//Deleting all memory used
// 	//Deletes the graph and al the Area in the graph
// 	delete graph;

// 	delete edgeIter;
// 	delete areaIter;
// 	return 0;
// }

void isAccessible(Area *a1, Area *a2, WarMap *graph)
{
	cout << a2->getName() << (graph->isAccessible(a1, a2) == true ? " is" : " is not") << " accessible from " << a1->getName() << endl;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph, string type)
{
	cout << a2->getName() << (graph->isAccessible(a1, a2, type) == true ? " is" : " is not") << " accessible from " << a1->getName() << " via " << type << endl;
}