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

void testMemento(){
    /* Communication *c;
     WarMap *map = new WarMap();
     vector<Country *> countrygroup;
     Country *america = new Country(America, c, 20);
     Country *columbia = new Country("Columbia", c, 25);
     countrygroup.push_back(america);
     countrygroup.push_back(columbia);

     vector<Area *> areas;
     areas.push_back(new Area("Caeser's Palace", america));



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
     delete history;*/
};

void testWarEngine()
{
    WarEngine *game = new WarEngine();

    string America = "America";
    game->addCountry(America, 20);
    string NewYork = "New York";
    string Sydney = "Sydney";
    string LasVegas = "Las Vegas";
    game->addArea(NewYork, America);
    game->addArea(Sydney, America);
    game->addArea(LasVegas, America);
    game->addConnection(::iRoad, NewYork, Sydney, 20);
    game->addConnection(::iRoad, Sydney, LasVegas, 40);
    game->addConnection(::iRoad, NewYork, LasVegas, 20);
    game->addConnection(::iHarbour, NewYork, LasVegas, 10);
    game->addConnection(::iHarbour, NewYork, Sydney, 15);
    game->addConnection(::iRunway, LasVegas, NewYork, 60);
    game->addInfrastructure(::iGroundCamp, LasVegas);
    game->addInfrastructure(::iNavyCamp, NewYork);
    game->addInfrastructure(::iAirforceCamp, Sydney);
    game->addInfrastructure(::iAircraftFactory, LasVegas);
    game->addInfrastructure(::iAquaticFactory, Sydney);
    game->addInfrastructure(::iLandFactory, Sydney);
    game->addInfrastructure(::iLandDevlopment, NewYork);
    game->addInfrastructure(::iAircraftFactory, LasVegas);
    game->addTroops(NewYork, ::tNavy, ::theSoldiers);
    game->addVehicles(LasVegas, ::landVehicle);
    game->moveTroops(Sydney, America);
    game->moveVehicles(NewYork, America);
    cout << "America has been built baby!!!!!" << endl;
    cout << "Guns for everyone!!!!!!" << endl;

    std::cout << "Creating Canada" << std::endl;
    game->addCountry("Canada", 100);

    game->addArea("Montreal", "Canada");
    game->addArea("Quebec", "Canada");
    game->addArea("Toronto", "Canada");
    game->addArea("Vancouver", "Canada");

    game->addConnection(::iRoad, NewYork, "Montreal", 40);

    game->addConnection(::iRoad, "Quebec", "Montreal", 40);
    game->addConnection(::iRoad, "Montreal", "Toronto", 70);
    game->addConnection(::iRoad, "Toronto", "Vancouver", 80);
    game->addConnection(::iRoad, "Vancouver", "Montreal", 80);

    game->addInfrastructure(::iHarbour, "Quebec");
    game->addInfrastructure(::iHarbour, "Toronto");
    game->addInfrastructure(::iHarbour, "Vancouver");
    game->addInfrastructure(::iRunway, "Montreal");
    game->addInfrastructure(::iRunway, "Quebec");
    game->addInfrastructure(::iGroundCamp, "Vancouver");
    game->addInfrastructure(::iNavyCamp, "Toronto");
    game->addInfrastructure(::iAirforceCamp, "Montreal");
    game->addInfrastructure(::iLandFactory, "Vancouver");
    game->addInfrastructure(::iLandFactory, "Vancouver");
    game->addInfrastructure(::iAircraftFactory, "Montreal");
    game->addInfrastructure(::iAquaticFactory, "Montreal");
    game->addInfrastructure(::iLandDevlopment, "Toronto");
    game->addInfrastructure(::iAircraftDevelopment, "Vancouver");
    game->addInfrastructure(::iAquaticDevelopment, "Montreal");

    std::cout << "Canada has been built, sorry" << std::endl;
    delete game;
    cout << "Everything was deleted" << endl;
}

void testTroopCreation(WarEngine *game)
{
}

int main()
{
    cout << "=============================Start testing=============================" << endl;
    // cout << "Troops Success!" << endl;
    // testMap();
    // testMemento();
    // showcasing();
    testWarEngine();
    cout << "=============================End testing===============================" << endl;
    return 0;
}