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

int main() {
    cout << "=============================Start testing=============================" << endl;
    testAllTroops();
    cout << "Troops Success!" << endl;
    cout << "=============================End testing=============================" << endl;
    return 0;
}