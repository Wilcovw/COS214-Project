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
    Area* testArea = new Area();

    TroopType* testGeneral = new Generals();
    TroopType* testSoldier = new Soldiers();
    TroopType* testMedic = new Medics();

    Troops* testGroundTroops = new GroundTroops(testArea, testSoldier);
    Troops* testNavy = new Navy(testArea, testMedic);
    Troops* testAirforce = new Airforce(testArea, testSoldier);

    TrainingCamp* testGroundTraining = new GroundTroopTraining();
    TrainingCamp* testNavyTraining = new NavyTraining();
    TrainingCamp* testAirforceTraining = new AirforceTraining();

    
    delete testGroundTraining;
    delete testNavyTraining;
    delete testAirforceTraining;
    delete testGeneral;
    delete testSoldier;
    delete testMedic;
    delete testGroundTroops;
    delete testNavy;
    delete testAirforce;
    delete testArea;
};

void testVehiclesAndFactories() {
    
    

    //Vehicles and Factories
    TestVehiclesCloneAndFactories *testVehiclesCloneAndFactories = new TestVehiclesCloneAndFactories();
    testVehiclesCloneAndFactories->testVehicles(10);
    testVehiclesCloneAndFactories->testFactory(10);
    testVehiclesCloneAndFactories->testMultipleClones(10);
    testVehiclesCloneAndFactories->testAddingToDevList();

    delete testVehiclesCloneAndFactories;
};

int main() {
    cout << "=============================Start testing=============================" << endl;
    testAllTroops();
    cout << "Troops Success!" << endl;
    testVehiclesAndFactories();
    cout << "Vehicles and Factories Success!" << endl;
    cout << "=============================End testing=============================" << endl;
    return 0;
}