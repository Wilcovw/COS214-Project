#include "Area.h"
#include "WarMap.h"
#include "AreaIterator.h"
#include "CommunicationBroadcast.h"
#include "Relationship.h"
#include "Country.h"
#include "WarEntities.h"
#include "TrainingCamp.h"
#include "Generals.h"
#include "Infrastructure.h"
#include "LandVehicleFactory.h"
#include "TroopType.h"
#include "Troops.h"
#include "TrainingCamp.h"
#include "Generals.h"
#include "Soldiers.h"
#include "Medics.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "GroundTroops.h"
#include "NavyTraining.h"
#include "AirforceTraining.h"
#include "GroundTroopTraining.h"
#include "TestVehiclesCloneAndFactories.h"
#include "Road.h"
#include "Harbour.h"
#include "Runway.h"
#include <iostream>
using namespace std;

void testAllTroops() {
	CommunicationBroadcast* testCommunicationBroadcast = new CommunicationBroadcast();
	Country* testCountry = new Country("", testCommunicationBroadcast);
    Area* testArea = new Area("", testCountry);

    TroopType* testGeneral = new Generals();
    TroopType* testSoldier = new Soldiers();
    TroopType* testMedic = new Medics();

	Citizens* testCitizens = new Citizens();

    Troops* testGroundTroops = new GroundTroops(testArea, testSoldier, testCitizens);
    Troops* testNavy = new Navy(testArea, testMedic, testCitizens);
    Troops* testAirforce = new Airforce(testArea, testSoldier, testCitizens);

    TrainingCamp* testGroundTraining = new GroundTroopTraining(1, testArea);
    TrainingCamp* testNavyTraining = new NavyTraining(1, testArea);
    TrainingCamp* testAirforceTraining = new AirforceTraining(1, testArea);

    
    delete testGroundTraining;
    delete testNavyTraining;
    delete testAirforceTraining;
    delete testGeneral;
    delete testSoldier;
    delete testMedic;
    delete testGroundTroops;
    delete testNavy;
    delete testAirforce;
	delete testCountry;
};

void testMap() {
    CommunicationBroadcast* communication = new CommunicationBroadcast();
	Country* america = new Country("America", communication);
    Area* newYork = new Area("NewYork", america);
    Area* sydney = new Area("Sydney", america);
    Area* lasVegas = new Area("LasVegas", america);
    WarMap* graph = new WarMap();
    graph->addArea(sydney);
    graph->addArea(newYork);
    graph->addArea(lasVegas);
    Road *r1 = new Road(newYork, sydney, 2);
    Harbour *h1 = new Harbour(newYork, 2);
    h1->addConnection(sydney);
    Runway *rw1 = new Runway(newYork, 2);
    rw1->addConnection(sydney);
    rw1->addConnection(lasVegas);
    
    r1->destroy();
    h1->destroy();
    rw1->destroy();
    //Code to interface with all the Areas in a graph
    AreaIterator *areaIter = graph->createAreaIterator();
	areaIter->first();
	while(areaIter->isDone() == false){
		Area* currentArea = areaIter->currentItem();
		cout << currentArea->getName() << endl;

		areaIter->next();
	}


    //Code to get all the edges in the graph

    EdgeIterator *edgeIter = graph->createEdgeIterator();
	edgeIter->first();
	while(edgeIter->isDone() == false){
		Edge* currentEdge = edgeIter->currentItem();
		cout << currentEdge->getDescription() << endl;
		edgeIter->next();
    }


};

int main() {
    cout << "=============================Start testing=============================" << endl;
    // testAllTroops();
    // cout << "Troops Success!" << endl;
    testMap();
    cout << "=============================End testing=============================" << endl;
    return 0;
}