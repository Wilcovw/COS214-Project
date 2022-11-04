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
#include "SpecialForces.h"
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

void populate(WarEngine *game)
{
    // Teams
    string Blue = "Blue";
    string Red = "Red";

    // Countries
    string UK = "United Kingdom";
    string Ireland = "Ireland";
    string France = "France";
    string Germany = "Germany";
    string Netherlands = "Netherlands";
    string Denmark = "Denmark";
    string Belgium = "Belgium";

    game->addCountry(UK, 673);
    game->addCountry(Ireland, 50);
    game->addCountry(France, 675);
    game->addCountry(Germany, 831);
    game->addCountry(Netherlands, 175);
    game->addCountry(Denmark, 58);
    game->addCountry(Belgium, 116);

    game->addRelationship("All countries");
    game->addRelationship(Red);
    game->addRelationship(Blue);
    game->addCountrytoRelationship(UK, Red);
    game->addCountrytoRelationship(France, Red);
    game->addCountrytoRelationship(Denmark, Red);
    game->addCountrytoRelationship(Germany, Blue);
    game->addCountrytoRelationship(Netherlands, Blue);
    game->addCountrytoRelationship(Belgium, Blue);
    game->addCountrytoRelationship(Ireland, Blue);
    game->addRelationshipToRelationship("All countries", Red);
    game->addRelationshipToRelationship("All countries", Blue);

    // Populate areas of UK
    string Scotland = "Scotland";
    string London = "London";
    string NorthernIreland = "Northern Ireland";
    string Wales = "Wales";
    game->addArea(Scotland, UK);
    game->addArea(Wales, UK);
    game->addArea(London, UK);
    game->addArea(NorthernIreland, UK);
    game->addConnection(::iRoad, London, Scotland, 678);
    game->addConnection(::iRoad, London, Wales, 203);
    game->addInfrastructure(::iHarbour, London);
    game->addInfrastructure(::iHarbour, NorthernIreland);
    game->addInfrastructure(::iHarbour, Wales);
    game->addInfrastructure(::iRunway, London);
    game->addInfrastructure(::iRunway, Scotland);
    game->addInfrastructure(::iAirforceCamp, London);
    game->addTroops(London, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->addTroops(London, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 90; i++)
    {
        game->addTroops(London, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, London);
    game->addTroops(London, ::tNavy, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->addTroops(London, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 100; i++)
    {
        game->addTroops(London, ::tNavy, ::theSoldiers);
    }

    game->addInfrastructure(::iGroundCamp, London);
    game->addInfrastructure(::iGroundCamp, Wales);
    game->addTroops(London, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->addTroops(London, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 70; i++)
    {
        game->addTroops(Wales, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, NorthernIreland);
    game->addInfrastructure(::iLandFactory, Scotland);
    game->addInfrastructure(::iAircraftFactory, London);
    game->addInfrastructure(::iAquaticFactory, London);
    game->addInfrastructure(::iAquaticFactory, Wales);

    for (int i = 0; i < 25; i++)
    {
        game->addVehicles(NorthernIreland, ::landVehicle);
    }
    for (int i = 0; i < 30; i++)
    {
        game->addVehicles(London, ::aircraftVehicle);
        game->addVehicles(Wales, ::aquaticVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->addVehicles(London, ::aquaticVehicle);
    }

    game->addInfrastructure(::iLandDevelopment, London);
    game->addInfrastructure(::iLandDevelopment, NorthernIreland);
    game->addInfrastructure(::iAquaticDevelopment, London);
    game->addInfrastructure(::iAquaticDevelopment, Wales);
    game->addInfrastructure(::iAircraftDevelopment, London);
    game->upgradeVehiclesInArea(::landVehicle, NorthernIreland);
    game->upgradeVehiclesInArea(::landVehicle, NorthernIreland);
    game->upgradeVehiclesInArea(::aquaticVehicle, London);
    game->upgradeVehiclesInArea(::aircraftVehicle, London);

    // Populate areas of Ireland
    string Dublin = "Dublin";
    string Cork = "Cork";
    string Limerick = "Limerick";
    string Galway = "Galway";
    game->addArea(Dublin, Ireland);
    game->addArea(Cork, Ireland);
    game->addArea(Limerick, Ireland);
    game->addArea(Galway, Ireland);
    game->addConnection(::iRoad, Dublin, NorthernIreland, 140);
    game->addConnection(::iRoad, Dublin, Cork, 210);
    game->addConnection(::iRoad, Dublin, Limerick, 170);
    game->addConnection(::iRoad, Dublin, Galway, 175);
    game->addConnection(::iRoad, Limerick, Cork, 85);
    game->addConnection(::iRoad, Limerick, Galway, 73);
    game->addInfrastructure(::iHarbour, Dublin);
    game->addInfrastructure(::iRunway, Dublin);
    game->addInfrastructure(::iAirforceCamp, Dublin);
    game->addTroops(Dublin, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 8; i++)
    {
        game->addTroops(Dublin, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, Dublin);
    game->addTroops(Dublin, ::tNavy, ::theGenerals);
    for (int i = 0; i < 4; i++)
    {
        game->addTroops(Dublin, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 8; i++)
    {
        game->addTroops(Dublin, ::tNavy, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Dublin);
    game->addInfrastructure(::iGroundCamp, Limerick);
    game->addTroops(Dublin, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 2; i++)
    {
        game->addTroops(Dublin, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Limerick, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, Cork);
    game->addInfrastructure(::iAircraftFactory, Dublin);
    game->addInfrastructure(::iAquaticFactory, Dublin);
    for (int i = 0; i < 30; i++)
    {
        game->addVehicles(Cork, ::landVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->addVehicles(Dublin, ::aircraftVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->addVehicles(Dublin, ::aquaticVehicle);
    }

    game->addInfrastructure(::iLandDevelopment, Cork);
    game->addInfrastructure(::iAquaticDevelopment, Dublin);
    game->addInfrastructure(::iAircraftDevelopment, Dublin);
    game->upgradeVehiclesInArea(::landVehicle, Cork);
    game->upgradeVehiclesInArea(::aquaticVehicle, Dublin);
    game->upgradeVehiclesInArea(::aircraftVehicle, Dublin);

    // Populate areas of France
    string Paris = "Paris";
    string Nantes = "Nantes";
    string Toulouse = "Toulouse";
    string Marseille = "Marseille";
    string Lille = "Lille";
    string Strasbourg = "Strasbourg";
    string Lyon = "Lyon";
    game->addArea(Paris, France);
    game->addArea(Nantes, France);
    game->addArea(Toulouse, France);
    game->addArea(Lille, France);
    game->addArea(Marseille, France);
    game->addArea(Strasbourg, France);
    game->addArea(Lyon, France);
    game->addConnection(::iRoad, Paris, Nantes, 345);
    game->addConnection(::iRoad, Paris, Toulouse, 580);
    game->addConnection(::iRoad, Paris, Lille, 213);
    game->addConnection(::iRoad, Paris, Strasbourg, 377);
    game->addConnection(::iRoad, Paris, Lyon, 80);
    game->addConnection(::iRoad, Lyon, Marseille, 272);
    game->addConnection(::iRoad, Lyon, Strasbourg, 380);
    game->addConnection(::iRoad, Lyon, Toulouse, 368);
    game->addConnection(::iRoad, Strasbourg, Lille, 410);
    game->addConnection(::iRoad, Toulouse, Nantes, 475);
    game->addConnection(::iRoad, Toulouse, Marseille, 320);
    game->addInfrastructure(::iHarbour, Marseille);
    game->addInfrastructure(::iHarbour, Nantes);
    game->addInfrastructure(::iRunway, Paris);
    game->addInfrastructure(::iRunway, Toulouse);
    game->addInfrastructure(::iAirforceCamp, Paris);
    game->addTroops(Paris, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->addTroops(Paris, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 70; i++)
    {
        game->addTroops(Paris, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, Marseille);
    game->addTroops(Marseille, ::tNavy, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Marseille, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 45; i++)
    {
        game->addTroops(Marseille, ::tNavy, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Lille);
    game->addInfrastructure(::iGroundCamp, Paris);
    game->addTroops(Paris, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 30; i++)
    {
        game->addTroops(Paris, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 150; i++)
    {
        game->addTroops(Paris, ::tGroundTroops, ::theSoldiers);
        game->addTroops(Lille, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, Nantes);
    game->addInfrastructure(::iLandFactory, Lyon);
    game->addInfrastructure(::iLandFactory, Strasbourg);
    game->addInfrastructure(::iLandFactory, Lille);
    game->addInfrastructure(::iAircraftFactory, Paris);
    game->addInfrastructure(::iAquaticFactory, Nantes);
    for (int i = 0; i < 40; i++)
    {
        game->addVehicles(Nantes, ::landVehicle);
        game->addVehicles(Lyon, ::landVehicle);
        game->addVehicles(Strasbourg, ::landVehicle);
        game->addVehicles(Lille, ::landVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->addVehicles(Paris, ::aircraftVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->addVehicles(Nantes, ::aquaticVehicle);
    }

    game->addInfrastructure(::iLandDevelopment, Nantes);
    game->addInfrastructure(::iLandDevelopment, Toulouse);
    game->addInfrastructure(::iAquaticDevelopment, Nantes);
    game->addInfrastructure(::iAquaticDevelopment, Marseille);
    game->addInfrastructure(::iAircraftDevelopment, Paris);
    game->addInfrastructure(::iAircraftDevelopment, Lyon);
    game->upgradeVehiclesInArea(::landVehicle, Nantes);
    game->upgradeVehiclesInArea(::aquaticVehicle, Nantes);
    game->upgradeVehiclesInArea(::aircraftVehicle, Paris);

    // Populate areas of Germany
    string Berlin = "Berlin";
    string Bremen = "Bremen";
    string Hannover = "Hannover";
    string Dusseldorf = "Dusseldorf";
    string Stuttgart = "Stuttgart";
    string Munich = "Munich";
    game->addArea(Berlin, Germany);
    game->addArea(Bremen, Germany);
    game->addArea(Hannover, Germany);
    game->addArea(Dusseldorf, Germany);
    game->addArea(Stuttgart, Germany);
    game->addArea(Munich, Germany);
    game->addConnection(::iRoad, Strasbourg, Stuttgart, 105);
    game->addConnection(::iRoad, Dusseldorf, Stuttgart, 320);
    game->addConnection(::iRoad, Berlin, Stuttgart, 513);
    game->addConnection(::iRoad, Munich, Stuttgart, 194);
    game->addConnection(::iRoad, Berlin, Munich, 515);
    game->addConnection(::iRoad, Berlin, Bremen, 318);
    game->addConnection(::iRoad, Hannover, Bremen, 95);
    game->addConnection(::iRoad, Hannover, Berlin, 249);
    game->addConnection(::iRoad, Hannover, Dusseldorf, 231);
    game->addInfrastructure(::iHarbour, Munich);
    game->addInfrastructure(::iRunway, Stuttgart);
    game->addInfrastructure(::iRunway, Berlin);
    game->addInfrastructure(::iAirforceCamp, Berlin);
    game->addTroops(Berlin, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->addTroops(Berlin, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 120; i++)
    {
        game->addTroops(Berlin, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, Munich);
    game->addTroops(Munich, ::tNavy, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->addTroops(Munich, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 55; i++)
    {
        game->addTroops(Munich, ::tNavy, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Berlin);
    game->addInfrastructure(::iGroundCamp, Stuttgart);
    game->addTroops(Berlin, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 50; i++)
    {
        game->addTroops(Berlin, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 160; i++)
    {
        game->addTroops(Berlin, ::tGroundTroops, ::theSoldiers);
        game->addTroops(Stuttgart, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, Dusseldorf);
    game->addInfrastructure(::iLandFactory, Bremen);
    game->addInfrastructure(::iLandFactory, Munich);
    game->addInfrastructure(::iAircraftFactory, Berlin);
    game->addInfrastructure(::iAquaticFactory, Munich);
    for (int i = 0; i < 40; i++)
    {
        game->addVehicles(Dusseldorf, ::landVehicle);
        game->addVehicles(Bremen, ::landVehicle);
        game->addVehicles(Munich, ::landVehicle);
    }
    for (int i = 0; i < 25; i++)
    {
        game->addVehicles(Berlin, ::aircraftVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->addVehicles(Munich, ::aquaticVehicle);
    }

    game->addInfrastructure(::iLandDevelopment, Dusseldorf);
    game->addInfrastructure(::iLandDevelopment, Bremen);
    game->addInfrastructure(::iLandDevelopment, Munich);
    game->addInfrastructure(::iAquaticDevelopment, Munich);
    game->addInfrastructure(::iAircraftDevelopment, Berlin);
    game->upgradeVehiclesInArea(::landVehicle, Dusseldorf);
    game->upgradeVehiclesInArea(::landVehicle, Bremen);
    game->upgradeVehiclesInArea(::landVehicle, Munich);
    game->upgradeVehiclesInArea(::aquaticVehicle, Munich);
    game->upgradeVehiclesInArea(::aircraftVehicle, Berlin);

    // Populate areas of Netherlands
    string Amsterdam = "Amsterdam";
    game->addArea(Amsterdam, Netherlands);
    game->addConnection(::iRoad, Amsterdam, Hannover, 320);
    game->addConnection(::iRoad, Amsterdam, Bremen, 278);
    game->addConnection(::iRoad, Amsterdam, Dusseldorf, 165);
    game->addInfrastructure(::iHarbour, Amsterdam);
    game->addInfrastructure(::iRunway, Amsterdam);
    game->addInfrastructure(::iAirforceCamp, Amsterdam);
    game->addTroops(Amsterdam, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->addTroops(Amsterdam, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 15; i++)
    {
        game->addTroops(Amsterdam, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, Amsterdam);
    game->addTroops(Amsterdam, ::tNavy, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->addTroops(Amsterdam, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 20; i++)
    {
        game->addTroops(Amsterdam, ::tNavy, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Amsterdam);
    game->addTroops(Amsterdam, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->addTroops(Amsterdam, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 20; i++)
    {
        game->addTroops(Amsterdam, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, Amsterdam);
    game->addInfrastructure(::iAircraftFactory, Amsterdam);
    game->addInfrastructure(::iAquaticFactory, Amsterdam);
    for (int i = 0; i < 20; i++)
    {
        game->addVehicles(Amsterdam, ::landVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->addVehicles(Amsterdam, ::aircraftVehicle);
    }
    for (int i = 0; i < 60; i++)
    {
        game->addVehicles(Amsterdam, ::aquaticVehicle);
    }
    game->addInfrastructure(::iAircraftDevelopment, Amsterdam);
    game->addInfrastructure(::iLandDevelopment, Amsterdam);
    game->addInfrastructure(::iAquaticDevelopment, Amsterdam);
    game->upgradeVehiclesInArea(::landVehicle, Amsterdam);
    game->upgradeVehiclesInArea(::aircraftVehicle, Amsterdam);
    game->upgradeVehiclesInArea(::aquaticVehicle, Amsterdam);

    // Populate areas of Denmark
    string Copenhagen = "Copenhagen";
    string Abenta = "Abenta";
    string Alborg = "Alborg";
    game->addArea(Copenhagen, Denmark);
    game->addArea(Abenta, Denmark);
    game->addArea(Alborg, Denmark);
    game->addConnection(::iRoad, Bremen, Abenta, 190);
    game->addConnection(::iRoad, Abenta, Berlin, 367);
    game->addConnection(::iRoad, Copenhagen, Abenta, 290);
    game->addConnection(::iRoad, Alborg, Abenta, 250);
    game->addConnection(::iRoad, Copenhagen, Alborg, 370);
    game->addInfrastructure(::iHarbour, Copenhagen);
    game->addInfrastructure(::iHarbour, Alborg);
    game->addInfrastructure(::iRunway, Abenta);
    game->addInfrastructure(::iAirforceCamp, Abenta);
    game->addTroops(Abenta, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->addTroops(Abenta, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Abenta, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iNavyCamp, Copenhagen);
    game->addTroops(Copenhagen, ::tNavy, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->addTroops(Copenhagen, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Copenhagen, ::tNavy, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Copenhagen);
    game->addTroops(Copenhagen, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->addTroops(Copenhagen, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Copenhagen, ::tGroundTroops, ::theSoldiers);
    }

    game->addInfrastructure(::iLandFactory, Copenhagen);
    game->addInfrastructure(::iAircraftFactory, Abenta);
    game->addInfrastructure(::iAquaticFactory, Alborg);
    for (int i = 0; i < 30; i++)
    {
        game->addVehicles(Copenhagen, ::landVehicle);
    }
    for (int i = 0; i < 25; i++)
    {
        game->addVehicles(Abenta, ::aircraftVehicle);
    }
    for (int i = 0; i < 30; i++)
    {
        game->addVehicles(Alborg, ::aquaticVehicle);
    }

    game->addInfrastructure(::iLandDevelopment, Copenhagen);
    game->addInfrastructure(::iAquaticDevelopment, Alborg);
    game->addInfrastructure(::iAircraftDevelopment, Abenta);
    game->upgradeVehiclesInArea(::landVehicle, Copenhagen);
    game->upgradeVehiclesInArea(::aquaticVehicle, Alborg);
    game->upgradeVehiclesInArea(::aircraftVehicle, Abenta);

    // Populate areas of Belgium
    string Brussels = "Brussels";
    game->addArea(Brussels, Belgium);
    game->addConnection(::iRoad, Brussels, Amsterdam, 175);
    game->addConnection(::iRoad, Brussels, Lille, 93);
    game->addConnection(::iRoad, Brussels, Dusseldorf, 176);
    game->addInfrastructure(::iRunway, Brussels);
    game->addInfrastructure(::iAirforceCamp, Brussels);
    game->addTroops(Brussels, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Brussels, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 10; i++)
    {
        game->addTroops(Brussels, ::tAirforce, ::theSoldiers);
    }
    game->addInfrastructure(::iGroundCamp, Brussels);
    game->addTroops(Brussels, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->addTroops(Brussels, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 10; i++)
    {
        game->addTroops(Brussels, ::tGroundTroops, ::theSoldiers);
    }
    game->addInfrastructure(::iLandFactory, Brussels);
    game->addInfrastructure(::iAircraftFactory, Brussels);

    for (int i = 0; i < 20; i++)
    {
        game->addVehicles(Brussels, ::landVehicle);
    }
    for (int i = 0; i < 65; i++)
    {
        game->addVehicles(Brussels, ::aircraftVehicle);
    }
    game->addInfrastructure(::iLandDevelopment, Brussels);     //                                                   __
    game->addInfrastructure(::iAircraftDevelopment, Brussels); //                                                 <(o )___
    game->upgradeVehiclesInArea(::landVehicle, Brussels);      //                                                  ( ._> /
    game->upgradeVehiclesInArea(::aircraftVehicle, Brussels);  //                                                   `---'

    // Add connections for harbours
    game->addConnection(::iHarbour, Dublin, Wales, 170);
    game->addConnection(::iHarbour, Dublin, NorthernIreland, 250);
    game->addConnection(::iHarbour, Dublin, Nantes, 605);
    game->addConnection(::iHarbour, Wales, London, 405);
    game->addConnection(::iHarbour, London, Amsterdam, 212);
    game->addConnection(::iHarbour, Alborg, London, 630);
    game->addConnection(::iHarbour, Alborg, Copenhagen, 613);
    game->addConnection(::iHarbour, Nantes, Amsterdam, 985);
    game->addConnection(::iHarbour, NorthernIreland, Wales, 175);
    game->addConnection(::iHarbour, Munich, Marseille, 770);
    game->addConnection(::iHarbour, Dublin, Amsterdam, 850);
    game->addConnection(::iHarbour, Amsterdam, Alborg, 602);
    game->addConnection(::iHarbour, Nantes, Wales, 786);

    // Add connection to runways
    game->addConnection(::iRunway, London, Scotland, 670);
    game->addConnection(::iRunway, Dublin, London, 450);
    game->addConnection(::iRunway, Dublin, Scotland, 430);
    game->addConnection(::iRunway, London, Paris, 350);
    game->addConnection(::iRunway, London, Amsterdam, 360);
    game->addConnection(::iRunway, London, Brussels, 325);
    game->addConnection(::iRunway, London, Abenta, 735);
    game->addConnection(::iRunway, Paris, Toulouse, 590);
    game->addConnection(::iRunway, Berlin, Stuttgart, 510);
    game->addConnection(::iRunway, Brussels, Amsterdam, 171);
    game->addConnection(::iRunway, Brussels, Stuttgart, 412);
    game->addConnection(::iRunway, Amsterdam, Abenta, 423);
    game->addConnection(::iRunway, Berlin, Amsterdam, 570);
    game->addConnection(::iRunway, Berlin, Abenta, 385);
    game->addConnection(::iRunway, Dublin, Brussels, 843);
    game->addConnection(::iRunway, Paris, Brussels, 258);
    game->addConnection(::iRunway, Paris, Stuttgart, 508);
    game->addConnection(::iRunway, Toulouse, Stuttgart, 836);

    game->distributeTroopsAndVehicles(France);
    game->distributeTroopsAndVehicles(Ireland);
    game->distributeTroopsAndVehicles(UK);
    game->distributeTroopsAndVehicles(Belgium);
    game->distributeTroopsAndVehicles(Netherlands);
    game->distributeTroopsAndVehicles(Germany);
    game->distributeTroopsAndVehicles(Denmark);

    game->printCountryStatus(France);
    game->attackArea(Stuttgart, France);
    game->printCountryStatus(France);

}

void finalMain()
{
    WarEngine *game = new WarEngine();
    populate(game);
}

int main()
{
    cout << "=============================Start testing=============================" << endl;
    // cout << "Troops Success!" << endl;
    // testMap();
    // testMemento();
    // showcasing();
    finalMain();
    cout << "=============================End testing===============================" << endl;
    return 0;
}