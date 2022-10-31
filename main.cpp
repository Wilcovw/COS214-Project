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
#include "WarEngine.h"
#include "AircraftFactory.h"
#include "AquaticVehicleFactory.h"
#include "LandVehicleFactory.h"
#include "LandVehicleDevelopment.h"
#include "AquaticVehicleDevelopment.h"
#include "AircraftDevelopment.h"
#include "TroopType.h"
#include <iostream>
using namespace std;

void testAllTroops()
{
    CommunicationBroadcast *testCommunicationBroadcast = new CommunicationBroadcast();
    Country *testCountry = new Country("bobbdBob", testCommunicationBroadcast, 400);
    Area *testArea = new Area("", testCountry);

    TroopType *testGeneral = new Generals();
    TroopType *testSoldier = new Soldiers();
    TroopType *testMedic = new Medics();

    Citizens *testCitizens = new Citizens();

    Troops *testGroundTroops = new GroundTroops(testArea, testSoldier, testCitizens);
    Troops *testNavy = new Navy(testArea, testMedic, testCitizens);
    Troops *testAirforce = new Airforce(testArea, testSoldier, testCitizens);

    TrainingCamp *testGroundTraining = new GroundTroopTraining(1, testArea);
    TrainingCamp *testNavyTraining = new NavyTraining(1, testArea);
    TrainingCamp *testAirforceTraining = new AirforceTraining(1, testArea);

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

void testMap()
{
    CommunicationBroadcast *communication = new CommunicationBroadcast();
    Country *america = new Country("America", communication, 20);
    Area *newYork = new Area("NewYork", america);
    Area *sydney = new Area("Sydney", america);
    Area *lasVegas = new Area("LasVegas", america);
    WarMap *graph = new WarMap();
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
    // Code to interface with all the Areas in a graph
    AreaIterator *areaIter = graph->createAreaIterator();
    areaIter->first();
    while (areaIter->isDone() == false)
    {
        Area *currentArea = areaIter->currentItem();
        cout << currentArea->getName() << endl;

        areaIter->next();
    }

    // Code to get all the edges in the graph

    EdgeIterator *edgeIter = graph->createEdgeIterator();
    edgeIter->first();
    while (edgeIter->isDone() == false)
    {
        Edge *currentEdge = edgeIter->currentItem();
        cout << currentEdge->getDescription() << endl;
        edgeIter->next();
    }
};

void testMemento()
{
    Communication *c;

    vector<Country *> countrygroup;
    Country *america = new Country("America", c, 20);
    Country *columbia = new Country("Columbia", c, 25);
    countrygroup.push_back(america);
    countrygroup.push_back(columbia);

    vector<Area *> areas;
    areas.push_back(new Area("Caeser's Palace", america));

    WarMap *map = new WarMap();

    WarHistory *history = new WarHistory();

    WarEngine *engine = new WarEngine(countrygroup, areas, *map);
    engine->addCountry(new Country("Sri Lanka", c, 30));
    engine->addArea(new Area("Escobar's Palace", columbia));

    cout << "-----Before Change-----" << endl;

    cout << "--Countries:--" << endl;
    for (int i = 0; i < engine->getCountryGroup().size(); i++)
    {
        cout << engine->getCountryGroup().at(i)->getName() << endl;
    }
    cout << "--Areas:--" << endl;
    for (int i = 0; i < engine->getWarTheatreGraph().size(); i++)
    {
        cout << engine->getWarTheatreGraph().at(i)->getName() << endl;
    }

    // Saving Current Snapshot
    history->storeMemento(engine->createMemento());

    Country *peru = new Country("peru", c, 15);
    columbia = peru;

    engine->removeCountryAt(0);
    engine->removeAreaAt(0);
    engine->removeAreaAt(0);

    vector<Area *> newAreas;
    newAreas.push_back(new Area("Paris", america));
    newAreas.push_back(new Area("Paris", america));

    engine->setWarTheatreGraph(newAreas);

    cout << "-----After Changes-----" << endl;
    cout << "--Countries:--" << endl;
    for (int i = 0; i < engine->getCountryGroup().size(); i++)
    {
        cout << engine->getCountryGroup().at(i)->getName() << endl;
    }
    cout << "--Areas:--" << endl;
    for (int i = 0; i < engine->getWarTheatreGraph().size(); i++)
    {
        cout << engine->getWarTheatreGraph().at(i)->getName() << endl;
    }

    // Reverting back
    engine->reinstateMemento(history->getLastMemento());

    cout << "-----Reverting Changes-----" << endl;
    for (int i = 0; i < engine->getCountryGroup().size(); i++)
    {
        cout << engine->getCountryGroup().at(i)->getName() << endl;
    }
    cout << "--Areas:--" << endl;
    for (int i = 0; i < engine->getWarTheatreGraph().size(); i++)
    {
        cout << engine->getWarTheatreGraph().at(i)->getName() << endl;
    }

    delete engine;
    delete history;
};

void showcasing()
{
    cout << "Creating Countries and Areas" << endl;
    Communication *communication = new CommunicationBroadcast();

    // Country : canada //////////////////////////////////////////////
    std::cout << "Creating Canada" << std::endl;
    Country *caneighdia = new Country("i", communication, 10);
    Area *quebecCity = new Area("Quebec", caneighdia);
    Area *montreal = new Area("Montreal", caneighdia);
    Area *toronto = new Area("Toronto", caneighdia);
    Area *vancouver = new Area("Vancouver", caneighdia);
    Road *cr1 = new Road(quebecCity, montreal, 2);
    caneighdia->getWarEntities()->addInfrastructure(cr1);
    Road *cr2 = new Road(montreal, toronto, 2);
    caneighdia->getWarEntities()->addInfrastructure(cr2);
    Road *cr3 = new Road(toronto, vancouver, 2);
    caneighdia->getWarEntities()->addInfrastructure(cr3);
    Road *cr4 = new Road(vancouver, montreal, 2);
    caneighdia->getWarEntities()->addInfrastructure(cr4);
    Harbour *ch1 = new Harbour(quebecCity, 2);
    caneighdia->getWarEntities()->addInfrastructure(ch1);
    Harbour *ch2 = new Harbour(toronto, 2);
    caneighdia->getWarEntities()->addInfrastructure(ch2);
    Harbour *ch3 = new Harbour(vancouver, 2);
    caneighdia->getWarEntities()->addInfrastructure(ch3);
    ch1->addConnection(toronto);
    Runway *crw1 = new Runway(montreal, 2);
    caneighdia->getWarEntities()->addInfrastructure(crw1);
    Runway *crw2 = new Runway(vancouver, 2);
    caneighdia->getWarEntities()->addInfrastructure(crw2);
    crw1->addConnection(vancouver);

    TrainingCamp *ctc1 = new GroundTroopTraining(2, vancouver);
    TrainingCamp *ctc2 = new NavyTraining(2, toronto);
    TrainingCamp *ctc3 = new AirforceTraining(2, montreal);
    Troops *cgt1 = ctc1->startDrafting(caneighdia->getCitizens()[0]);
    caneighdia->getWarEntities()->addTroops(cgt1);
    Troops *cgt2 = ctc2->startDrafting(caneighdia->getCitizens()[1]);
    caneighdia->getWarEntities()->addTroops(cgt2);
    Troops *cgt3 = ctc3->startDrafting(caneighdia->getCitizens()[2]);
    caneighdia->getWarEntities()->addTroops(cgt3);

    Factory *cvf1 = new LandVehicleFactory(2, vancouver);
    Factory *cvf2 = new AquaticVehicleFactory(2, toronto);
    Factory *cvf3 = new AircraftFactory(2, montreal);
    caneighdia->getWarEntities()->addVehicles(cvf1->createVehicle("Mercedes", 2, 2, 2));
    caneighdia->getWarEntities()->addVehicles(cvf2->createVehicle("Mercedes", 2, 2, 2));
    caneighdia->getWarEntities()->addVehicles(cvf3->createVehicle("Mercedes", 2, 2, 2));

    ResearchAndDevelopmentCentre *crdc1 = new LandVehicleDevelopment(2, vancouver);
    ResearchAndDevelopmentCentre *crdc2 = new AquaticVehicleDevelopment(2, toronto);
    ResearchAndDevelopmentCentre *crdc3 = new AircraftDevelopment(2, montreal);

    std::cout << "Canada has been built, sorry" << std::endl;

    // Country : Russia //////////////////////////////////////////////
    cout << "Creating Russia"
         << endl;
    Country *russia = new Country("Russia", communication, 25);
    Area *adygea = new Area("Adygea", russia);
    Area *buryatia = new Area("Buryatia", russia);
    Area *ingushetia = new Area("Ingushetia", russia);
    Area *kremlin = new Area("Kremlin", russia);
    Road *rr1 = new Road(adygea, kremlin, 2);
    Road *rr2 = new Road(ingushetia, kremlin, 2);
    Road *rr3 = new Road(buryatia, kremlin, 2);
    Harbour *rh1 = new Harbour(kremlin, 2);
    Runway *rrw = new Runway(kremlin, 2);
    russia->getWarEntities()->addInfrastructure(rr1);
    russia->getWarEntities()->addInfrastructure(rr2);
    russia->getWarEntities()->addInfrastructure(rr3);
    russia->getWarEntities()->addInfrastructure(rh1);
    russia->getWarEntities()->addInfrastructure(rrw);

    TrainingCamp *rtc = new GroundTroopTraining(2, kremlin);
    TrainingCamp *rtc2 = new NavyTraining(2, adygea);
    TrainingCamp *rtc3 = new AirforceTraining(2, ingushetia);
    russia->getWarEntities()->addInfrastructure(rtc);
    russia->getWarEntities()->addInfrastructure(rtc3);
    russia->getWarEntities()->addInfrastructure(rtc3);
    Factory *rf1 = new AircraftFactory(200, buryatia);
    Factory *rf2 = new AquaticVehicleFactory(50, buryatia);
    Factory *rf3 = new LandVehicleFactory(10, kremlin);
    russia->getWarEntities()->addInfrastructure(rf1);
    russia->getWarEntities()->addInfrastructure(rf2);
    russia->getWarEntities()->addInfrastructure(rf3);

    ResearchAndDevelopmentCentre *rrdc1 = new LandVehicleDevelopment(2, kremlin);
    ResearchAndDevelopmentCentre *rrdc2 = new AquaticVehicleDevelopment(2, buryatia);
    ResearchAndDevelopmentCentre *rrdc3 = new AircraftDevelopment(2, buryatia);
    russia->getWarEntities()->addInfrastructure(rrdc1);
    russia->getWarEntities()->addInfrastructure(rrdc2);
    russia->getWarEntities()->addInfrastructure(rrdc3);
    russia->getWarEntities()->addVehicles(rf3->createVehicle("AUDI", 20, 20, 120));
    russia->getWarEntities()->addVehicles(rf2->createVehicle("Submarine", 500, 100, 200));
    russia->getWarEntities()->addVehicles(rf2->createVehicle("Fighter Jet", 50, 30, 1000));
    Troops *rs1 = rtc->startDrafting(russia->getCitizens()[0]);
    russia->getWarEntities()->addTroops(rs1);
    Troops *rs2 = rtc2->startDrafting(russia->getCitizens()[1]);
    russia->getWarEntities()->addTroops(rs2);
    Troops *rs3 = rtc3->startDrafting(russia->getCitizens()[2]);
    russia->getWarEntities()->addTroops(rs3);

    cout << "Russia was built successfully" << endl;

    // Country : America //////////////////////////////////////////////
    Country *america = new Country("America", communication, 20);
    Area *newYork = new Area("NewYork", america);
    Area *sydney = new Area("Sydney", america);
    Area *lasVegas = new Area("LasVegas", america);
    Road *ar1 = new Road(newYork, sydney, 2);
    america->getWarEntities()->addInfrastructure(ar1);
    Road *ar2 = new Road(sydney, lasVegas, 2);
    america->getWarEntities()->addInfrastructure(ar2);
    Road *ar3 = new Road(newYork, lasVegas, 2);
    america->getWarEntities()->addInfrastructure(ar3);
    Harbour *ah1 = new Harbour(newYork, 2);
    america->getWarEntities()->addInfrastructure(ah1);
    Harbour *ah2 = new Harbour(sydney, 2);
    america->getWarEntities()->addInfrastructure(ah2);
    ah1->addConnection(sydney);
    Runway *arw1 = new Runway(newYork, 2);
    america->getWarEntities()->addInfrastructure(arw1);
    Runway *arw2 = new Runway(lasVegas, 2);
    america->getWarEntities()->addInfrastructure(arw2);
    arw1->addConnection(montreal);
    arw1->addConnection(lasVegas);
    ah1->addConnection(kremlin);
    arw1->addConnection(kremlin);
    Road *car1 = new Road(vancouver, lasVegas, 2);
    america->getWarEntities()->addInfrastructure(car1);
    TrainingCamp *atc1 = new GroundTroopTraining(2, lasVegas);
    TrainingCamp *atc2 = new NavyTraining(2, sydney);
    TrainingCamp *atc3 = new AirforceTraining(2, newYork);
    america->getWarEntities()->addInfrastructure(atc1);
    america->getWarEntities()->addInfrastructure(atc2);
    america->getWarEntities()->addInfrastructure(atc3);
    Factory *af1 = new AircraftFactory(2, newYork);
    Factory *af2 = new AquaticVehicleFactory(2, sydney);
    Factory *af3 = new LandVehicleFactory(2, lasVegas);
    america->getWarEntities()->addInfrastructure(af1);
    america->getWarEntities()->addInfrastructure(af2);
    america->getWarEntities()->addInfrastructure(af3);
    ResearchAndDevelopmentCentre *ardc1 = new LandVehicleDevelopment(2, sydney);
    ResearchAndDevelopmentCentre *ardc2 = new AquaticVehicleDevelopment(2, newYork);
    ResearchAndDevelopmentCentre *ardc3 = new AircraftDevelopment(2, lasVegas);
    america->getWarEntities()->addInfrastructure(ardc1);
    america->getWarEntities()->addInfrastructure(ardc2);
    america->getWarEntities()->addInfrastructure(ardc3);
    america->getWarEntities()->addVehicles(af1->createVehicle("BMW", 2, 2, 2));
    america->getWarEntities()->addVehicles(af2->createVehicle("FloatBoat", 2, 2, 2));
    america->getWarEntities()->addVehicles(af3->createVehicle("Fly@UP", 2, 2, 2));
    Troops *as1 = atc1->startDrafting(america->getCitizens()[0]);
    america->getWarEntities()->addTroops(as1);
    Troops *as2 = atc1->startDrafting(america->getCitizens()[1]);
    america->getWarEntities()->addTroops(as2);
    Troops *as3 = atc1->startDrafting(america->getCitizens()[2]);
    america->getWarEntities()->addTroops(as3);

    cout << "America has been built baby!!!!!" << endl;
    cout << "Guns for everyone!!!!!!" << endl;

    // Relationship //////////////////////////////////////////////
    Relationship *countriesAtWar = new Relationship("CountriesAtWar", communication);
    Relationship *northAmerica = new Relationship("northAmerica", communication);
    northAmerica->addAssociatedCountries(america);
    northAmerica->addAssociatedCountries(caneighdia);

    countriesAtWar->addAssociatedCountries(northAmerica);
    countriesAtWar->addAssociatedCountries(russia);

    WarMap *graph = new WarMap();
    cout << "Adding Areas to the graph" << endl;
    graph->addArea(sydney);
    graph->addArea(newYork);
    graph->addArea(lasVegas);
    graph->addArea(adygea);
    graph->addArea(buryatia);
    graph->addArea(ingushetia);
    graph->addArea(kremlin);
    graph->addArea(quebecCity);
    graph->addArea(montreal);
    graph->addArea(toronto);
    graph->addArea(vancouver);
    cout << "Graph was built successfully" << endl;
}

int main()
{
    cout << "=============================Start testing=============================" << endl;
    // testAllTroops();
    // cout << "Troops Success!" << endl;
    // testMap();
    // testMemento();
    showcasing();
    cout << "=============================End testing===============================" << endl;
    return 0;
}