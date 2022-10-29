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
#include "AssociatedCountries.h"
#include "Country.h"
#include "Relationship.h"
#include "CommunicationBroadcast.h"
#include "Citizens.h"

#include <iostream>
using namespace std;

void testAllTroops()
{
    Area *testArea = new Area();

    TroopType *testGeneral = new Generals();
    TroopType *testSoldier = new Soldiers();
    TroopType *testMedic = new Medics();

    Troops *testGroundTroops = new GroundTroops(testArea, testSoldier);
    Troops *testNavy = new Navy(testArea, testMedic);
    Troops *testAirforce = new Airforce(testArea, testSoldier);

    TrainingCamp *testGroundTraining = new GroundTroopTraining();
    TrainingCamp *testNavyTraining = new NavyTraining();
    TrainingCamp *testAirforceTraining = new AirforceTraining();

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

void testVehiclesAndFactories()
{

    // Vehicles and Factories
    TestVehiclesCloneAndFactories *testVehiclesCloneAndFactories = new TestVehiclesCloneAndFactories();
    testVehiclesCloneAndFactories->testVehicles(10);
    testVehiclesCloneAndFactories->testFactory(10);
    testVehiclesCloneAndFactories->testMultipleClones(10);
    testVehiclesCloneAndFactories->testAddingToDevList();

    delete testVehiclesCloneAndFactories;
};

void testCitizenCountry()
{
    Communication *tele = new CommunicationBroadcast();
    AssociatedCountries *countriesAtWar = new Relationship("Countries in the war", tele);
    AssociatedCountries *allies = new Relationship("Allies", tele);
    AssociatedCountries *axis = new Relationship("Axis", tele);
    Country *germany = new Country("Germany", tele);
    Citizens **citizens = germany->getCitizens();

    for (int i = 0; i < 5; i++)
    {
        citizens[i]->changeStatus();
        if (i == 3)
        {
            citizens[i]->die();
        }
    }

    for (int i = 0; i < germany->getNumCitzenGroups(); i++)
    {
        cout << "Group " << i << " citizens current state: " << citizens[i]->getStatus() << endl;
    }

    delete tele;
    delete countriesAtWar;
    delete allies;
    delete axis;
    delete citizens;

    // allies->addAssociatedCountries(new Country("England", tele));
    // allies->addAssociatedCountries(new Country("France", tele));
    // allies->addAssociatedCountries(new Country("America", tele));
    // allies->addAssociatedCountries(new Country("Poland", tele));
    // allies->addAssociatedCountries(new Country("Russia", tele));
    // countriesAtWar->addAssociatedCountries(allies);
    // axis->addAssociatedCountries(germany);
    // axis->addAssociatedCountries(new Country("Italy", tele));
    // countriesAtWar->addAssociatedCountries(axis);
    // countriesAtWar->addAssociatedCountries(new Country("Switzerland", tele));

    // std::cout << countriesAtWar->print();

    // axis->removeAssociatedCountries(germany);

    // std::cout << countriesAtWar->print();

    // germany->sendBroadcast(allies, "We (germany) declare war against you");
    // allies->sendBroadcast(germany, "We (allies) accept your declaration of war and respond in kind");
};

int main()
{
    cout << "=============================Start testing=============================" << endl;
    testAllTroops();
    cout << "Troops Success!" << endl;
    testVehiclesAndFactories();
    cout << "Vehicles and Factories Success!" << endl;
    testCitizenCountry();
    cout << "Citizens an Countries Success!" << endl;
    cout << "=============================End testing=============================" << endl;
    return 0;
}