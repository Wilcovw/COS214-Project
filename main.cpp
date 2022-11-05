#include "WarEngine.h"
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

    game->getPhase()->addCountry(UK, 673);
    game->getPhase()->addCountry(Ireland, 50);
    game->getPhase()->addCountry(France, 675);
    game->getPhase()->addCountry(Germany, 831);
    game->getPhase()->addCountry(Netherlands, 175);
    game->getPhase()->addCountry(Denmark, 58);
    game->getPhase()->addCountry(Belgium, 116);

    game->getPhase()->addRelationship("AllCountries");
    game->getPhase()->addRelationship(Red);
    game->getPhase()->addRelationship(Blue);
    game->getPhase()->addCountrytoRelationship(UK, Red);
    game->getPhase()->addCountrytoRelationship(France, Red);
    game->getPhase()->addCountrytoRelationship(Denmark, Red);
    game->getPhase()->addCountrytoRelationship(Germany, Blue);
    game->getPhase()->addCountrytoRelationship(Netherlands, Blue);
    game->getPhase()->addCountrytoRelationship(Belgium, Blue);
    game->getPhase()->addCountrytoRelationship(Ireland, Blue);
    game->getPhase()->addRelationshipToRelationship("All countries", Red);
    game->getPhase()->addRelationshipToRelationship("All countries", Blue);

    // Populate areas of UK
    string Scotland = "Scotland";
    string London = "London";
    string NorthernIreland = "Northern Ireland";
    string Wales = "Wales";
    game->getPhase()->addArea(Scotland, UK);
    game->getPhase()->addArea(Wales, UK);
    game->getPhase()->addArea(London, UK);
    game->getPhase()->addArea(NorthernIreland, UK);
    game->getPhase()->addConnection(::iRoad, London, Scotland, 678);
    game->getPhase()->addConnection(::iRoad, London, Wales, 203);
    game->getPhase()->addInfrastructure(::iHarbour, London);
    game->getPhase()->addInfrastructure(::iHarbour, NorthernIreland);
    game->getPhase()->addInfrastructure(::iHarbour, Wales);
    game->getPhase()->addInfrastructure(::iRunway, London);
    game->getPhase()->addInfrastructure(::iRunway, Scotland);
    game->getPhase()->addInfrastructure(::iAirforceCamp, London);
    game->getPhase()->addTroops(London, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(London, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 90; i++)
    {
        game->getPhase()->addTroops(London, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, London);
    game->getPhase()->addTroops(London, ::tNavy, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(London, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 100; i++)
    {
        game->getPhase()->addTroops(London, ::tNavy, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iGroundCamp, London);
    game->getPhase()->addInfrastructure(::iGroundCamp, Wales);
    game->getPhase()->addTroops(London, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addTroops(London, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 70; i++)
    {
        game->getPhase()->addTroops(Wales, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, NorthernIreland);
    game->getPhase()->addInfrastructure(::iLandFactory, Scotland);
    game->getPhase()->addInfrastructure(::iAircraftFactory, London);
    game->getPhase()->addInfrastructure(::iAquaticFactory, London);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Wales);

    for (int i = 0; i < 25; i++)
    {
        game->getPhase()->addVehicles(NorthernIreland, ::landVehicle);
    }
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addVehicles(London, ::aircraftVehicle);
        game->getPhase()->addVehicles(Wales, ::aquaticVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(London, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, London);
    game->getPhase()->addInfrastructure(::iLandDevelopment, NorthernIreland);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, London);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Wales);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, London);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, NorthernIreland);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, NorthernIreland);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, London);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, London);

    // Populate areas of Ireland
    string Dublin = "Dublin";
    string Cork = "Cork";
    string Limerick = "Limerick";
    string Galway = "Galway";
    game->getPhase()->addArea(Dublin, Ireland);
    game->getPhase()->addArea(Cork, Ireland);
    game->getPhase()->addArea(Limerick, Ireland);
    game->getPhase()->addArea(Galway, Ireland);
    game->getPhase()->addConnection(::iRoad, Dublin, NorthernIreland, 140);
    game->getPhase()->addConnection(::iRoad, Dublin, Cork, 210);
    game->getPhase()->addConnection(::iRoad, Dublin, Limerick, 170);
    game->getPhase()->addConnection(::iRoad, Dublin, Galway, 175);
    game->getPhase()->addConnection(::iRoad, Limerick, Cork, 85);
    game->getPhase()->addConnection(::iRoad, Limerick, Galway, 73);
    game->getPhase()->addInfrastructure(::iHarbour, Dublin);
    game->getPhase()->addInfrastructure(::iRunway, Dublin);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Dublin);
    game->getPhase()->addTroops(Dublin, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 8; i++)
    {
        game->getPhase()->addTroops(Dublin, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Dublin);
    game->getPhase()->addTroops(Dublin, ::tNavy, ::theGenerals);
    for (int i = 0; i < 4; i++)
    {
        game->getPhase()->addTroops(Dublin, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 8; i++)
    {
        game->getPhase()->addTroops(Dublin, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Dublin);
    game->getPhase()->addInfrastructure(::iGroundCamp, Limerick);
    game->getPhase()->addTroops(Dublin, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 2; i++)
    {
        game->getPhase()->addTroops(Dublin, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Limerick, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Cork);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Dublin);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Dublin);
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addVehicles(Cork, ::landVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(Dublin, ::aircraftVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Dublin, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, Cork);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Dublin);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Dublin);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Cork);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Dublin);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Dublin);

    // Populate areas of France
    string Paris = "Paris";
    string Nantes = "Nantes";
    string Toulouse = "Toulouse";
    string Marseille = "Marseille";
    string Lille = "Lille";
    string Strasbourg = "Strasbourg";
    string Lyon = "Lyon";
    game->getPhase()->addArea(Paris, France);
    game->getPhase()->addArea(Nantes, France);
    game->getPhase()->addArea(Toulouse, France);
    game->getPhase()->addArea(Lille, France);
    game->getPhase()->addArea(Marseille, France);
    game->getPhase()->addArea(Strasbourg, France);
    game->getPhase()->addArea(Lyon, France);
    game->getPhase()->addConnection(::iRoad, Paris, Nantes, 345);
    game->getPhase()->addConnection(::iRoad, Paris, Toulouse, 580);
    game->getPhase()->addConnection(::iRoad, Paris, Lille, 213);
    game->getPhase()->addConnection(::iRoad, Paris, Strasbourg, 377);
    game->getPhase()->addConnection(::iRoad, Paris, Lyon, 80);
    game->getPhase()->addConnection(::iRoad, Lyon, Marseille, 272);
    game->getPhase()->addConnection(::iRoad, Lyon, Strasbourg, 380);
    game->getPhase()->addConnection(::iRoad, Lyon, Toulouse, 368);
    game->getPhase()->addConnection(::iRoad, Strasbourg, Lille, 410);
    game->getPhase()->addConnection(::iRoad, Toulouse, Nantes, 475);
    game->getPhase()->addConnection(::iRoad, Toulouse, Marseille, 320);
    game->getPhase()->addInfrastructure(::iHarbour, Marseille);
    game->getPhase()->addInfrastructure(::iHarbour, Nantes);
    game->getPhase()->addInfrastructure(::iRunway, Paris);
    game->getPhase()->addInfrastructure(::iRunway, Toulouse);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Paris);
    game->getPhase()->addTroops(Paris, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addTroops(Paris, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 70; i++)
    {
        game->getPhase()->addTroops(Paris, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Marseille);
    game->getPhase()->addTroops(Marseille, ::tNavy, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Marseille, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 45; i++)
    {
        game->getPhase()->addTroops(Marseille, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Lille);
    game->getPhase()->addInfrastructure(::iGroundCamp, Paris);
    game->getPhase()->addTroops(Paris, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addTroops(Paris, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 150; i++)
    {
        game->getPhase()->addTroops(Paris, ::tGroundTroops, ::theSoldiers);
        game->getPhase()->addTroops(Lille, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Nantes);
    game->getPhase()->addInfrastructure(::iLandFactory, Lyon);
    game->getPhase()->addInfrastructure(::iLandFactory, Strasbourg);
    game->getPhase()->addInfrastructure(::iLandFactory, Lille);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Paris);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Nantes);
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addVehicles(Nantes, ::landVehicle);
        game->getPhase()->addVehicles(Lyon, ::landVehicle);
        game->getPhase()->addVehicles(Strasbourg, ::landVehicle);
        game->getPhase()->addVehicles(Lille, ::landVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Paris, ::aircraftVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(Nantes, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, Nantes);
    game->getPhase()->addInfrastructure(::iLandDevelopment, Toulouse);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Nantes);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Marseille);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Paris);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Lyon);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Nantes);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Nantes);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Paris);

    // Populate areas of Germany
    string Berlin = "Berlin";
    string Bremen = "Bremen";
    string Hannover = "Hannover";
    string Dusseldorf = "Dusseldorf";
    string Stuttgart = "Stuttgart";
    string Munich = "Munich";
    game->getPhase()->addArea(Berlin, Germany);
    game->getPhase()->addArea(Bremen, Germany);
    game->getPhase()->addArea(Hannover, Germany);
    game->getPhase()->addArea(Dusseldorf, Germany);
    game->getPhase()->addArea(Stuttgart, Germany);
    game->getPhase()->addArea(Munich, Germany);
    game->getPhase()->addConnection(::iRoad, Strasbourg, Stuttgart, 105);
    game->getPhase()->addConnection(::iRoad, Dusseldorf, Stuttgart, 320);
    game->getPhase()->addConnection(::iRoad, Berlin, Stuttgart, 513);
    game->getPhase()->addConnection(::iRoad, Munich, Stuttgart, 194);
    game->getPhase()->addConnection(::iRoad, Berlin, Munich, 515);
    game->getPhase()->addConnection(::iRoad, Berlin, Bremen, 318);
    game->getPhase()->addConnection(::iRoad, Hannover, Bremen, 95);
    game->getPhase()->addConnection(::iRoad, Hannover, Berlin, 249);
    game->getPhase()->addConnection(::iRoad, Hannover, Dusseldorf, 231);
    game->getPhase()->addInfrastructure(::iHarbour, Munich);
    game->getPhase()->addInfrastructure(::iRunway, Stuttgart);
    game->getPhase()->addInfrastructure(::iRunway, Berlin);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Berlin);
    game->getPhase()->addTroops(Berlin, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 120; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Munich);
    game->getPhase()->addTroops(Munich, ::tNavy, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addTroops(Munich, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 55; i++)
    {
        game->getPhase()->addTroops(Munich, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Berlin);
    game->getPhase()->addInfrastructure(::iGroundCamp, Stuttgart);
    game->getPhase()->addTroops(Berlin, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 50; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 160; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tGroundTroops, ::theSoldiers);
        game->getPhase()->addTroops(Stuttgart, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Dusseldorf);
    game->getPhase()->addInfrastructure(::iLandFactory, Bremen);
    game->getPhase()->addInfrastructure(::iLandFactory, Munich);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Berlin);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Munich);
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addVehicles(Dusseldorf, ::landVehicle);
        game->getPhase()->addVehicles(Bremen, ::landVehicle);
        game->getPhase()->addVehicles(Munich, ::landVehicle);
    }
    for (int i = 0; i < 25; i++)
    {
        game->getPhase()->addVehicles(Berlin, ::aircraftVehicle);
    }
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Munich, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, Dusseldorf);
    game->getPhase()->addInfrastructure(::iLandDevelopment, Bremen);
    game->getPhase()->addInfrastructure(::iLandDevelopment, Munich);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Munich);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Berlin);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Dusseldorf);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Bremen);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Munich);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Munich);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Berlin);

    // Populate areas of Netherlands
    string Amsterdam = "Amsterdam";
    game->getPhase()->addArea(Amsterdam, Netherlands);
    game->getPhase()->addConnection(::iRoad, Amsterdam, Hannover, 320);
    game->getPhase()->addConnection(::iRoad, Amsterdam, Bremen, 278);
    game->getPhase()->addConnection(::iRoad, Amsterdam, Dusseldorf, 165);
    game->getPhase()->addInfrastructure(::iHarbour, Amsterdam);
    game->getPhase()->addInfrastructure(::iRunway, Amsterdam);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Amsterdam);
    game->getPhase()->addTroops(Amsterdam, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Amsterdam);
    game->getPhase()->addTroops(Amsterdam, ::tNavy, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Amsterdam);
    game->getPhase()->addTroops(Amsterdam, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Amsterdam);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Amsterdam);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Amsterdam);
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Amsterdam, ::landVehicle);
    }
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(Amsterdam, ::aircraftVehicle);
    }
    for (int i = 0; i < 60; i++)
    {
        game->getPhase()->addVehicles(Amsterdam, ::aquaticVehicle);
    }
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Amsterdam);
    game->getPhase()->addInfrastructure(::iLandDevelopment, Amsterdam);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Amsterdam);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Amsterdam);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Amsterdam);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Amsterdam);

    // Populate areas of Denmark
    string Copenhagen = "Copenhagen";
    string Abenta = "Abenta";
    string Alborg = "Alborg";
    game->getPhase()->addArea(Copenhagen, Denmark);
    game->getPhase()->addArea(Abenta, Denmark);
    game->getPhase()->addArea(Alborg, Denmark);
    game->getPhase()->addConnection(::iRoad, Bremen, Abenta, 190);
    game->getPhase()->addConnection(::iRoad, Abenta, Berlin, 367);
    game->getPhase()->addConnection(::iRoad, Copenhagen, Abenta, 290);
    game->getPhase()->addConnection(::iRoad, Alborg, Abenta, 250);
    game->getPhase()->addConnection(::iRoad, Copenhagen, Alborg, 370);
    game->getPhase()->addInfrastructure(::iHarbour, Copenhagen);
    game->getPhase()->addInfrastructure(::iHarbour, Alborg);
    game->getPhase()->addInfrastructure(::iRunway, Abenta);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Abenta);
    game->getPhase()->addTroops(Abenta, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->getPhase()->addTroops(Abenta, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Abenta, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Copenhagen);
    game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Copenhagen);
    game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Copenhagen);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Abenta);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Alborg);
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addVehicles(Copenhagen, ::landVehicle);
    }
    for (int i = 0; i < 25; i++)
    {
        game->getPhase()->addVehicles(Abenta, ::aircraftVehicle);
    }
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addVehicles(Alborg, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, Copenhagen);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Alborg);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Abenta);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Copenhagen);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Alborg);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Abenta);

    // Populate areas of Belgium
    string Brussels = "Brussels";
    game->getPhase()->addArea(Brussels, Belgium);
    game->getPhase()->addConnection(::iRoad, Brussels, Amsterdam, 175);
    game->getPhase()->addConnection(::iRoad, Brussels, Lille, 93);
    game->getPhase()->addConnection(::iRoad, Brussels, Dusseldorf, 176);
    game->getPhase()->addInfrastructure(::iRunway, Brussels);
    game->getPhase()->addInfrastructure(::iAirforceCamp, Brussels);
    game->getPhase()->addTroops(Brussels, ::tAirforce, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Brussels, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addTroops(Brussels, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Brussels);
    game->getPhase()->addTroops(Brussels, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Brussels, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addTroops(Brussels, ::tGroundTroops, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iLandFactory, Brussels);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Brussels);

    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Brussels, ::landVehicle);
    }
    for (int i = 0; i < 65; i++)
    {
        game->getPhase()->addVehicles(Brussels, ::aircraftVehicle);
    }
    game->getPhase()->addInfrastructure(::iLandDevelopment, Brussels);     //                                                   __
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Brussels); //                                                 <(o )___
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Brussels);      //                                                  ( ._> /
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Brussels);  //                                                   `---'

    // Add connections for harbours
    game->getPhase()->addConnection(::iHarbour, Dublin, Wales, 170);
    game->getPhase()->addConnection(::iHarbour, Dublin, NorthernIreland, 250);
    game->getPhase()->addConnection(::iHarbour, Dublin, Nantes, 605);
    game->getPhase()->addConnection(::iHarbour, Wales, London, 405);
    game->getPhase()->addConnection(::iHarbour, London, Amsterdam, 212);
    game->getPhase()->addConnection(::iHarbour, Alborg, London, 630);
    game->getPhase()->addConnection(::iHarbour, Alborg, Copenhagen, 613);
    game->getPhase()->addConnection(::iHarbour, Nantes, Amsterdam, 985);
    game->getPhase()->addConnection(::iHarbour, NorthernIreland, Wales, 175);
    game->getPhase()->addConnection(::iHarbour, Munich, Marseille, 770);
    game->getPhase()->addConnection(::iHarbour, Dublin, Amsterdam, 850);
    game->getPhase()->addConnection(::iHarbour, Amsterdam, Alborg, 602);
    game->getPhase()->addConnection(::iHarbour, Nantes, Wales, 786);

    // Add connection to runways
    game->getPhase()->addConnection(::iRunway, London, Scotland, 670);
    game->getPhase()->addConnection(::iRunway, Dublin, London, 450);
    game->getPhase()->addConnection(::iRunway, Dublin, Scotland, 430);
    game->getPhase()->addConnection(::iRunway, London, Paris, 350);
    game->getPhase()->addConnection(::iRunway, London, Amsterdam, 360);
    game->getPhase()->addConnection(::iRunway, London, Brussels, 325);
    game->getPhase()->addConnection(::iRunway, London, Abenta, 735);
    game->getPhase()->addConnection(::iRunway, Paris, Toulouse, 590);
    game->getPhase()->addConnection(::iRunway, Berlin, Stuttgart, 510);
    game->getPhase()->addConnection(::iRunway, Brussels, Amsterdam, 171);
    game->getPhase()->addConnection(::iRunway, Brussels, Stuttgart, 412);
    game->getPhase()->addConnection(::iRunway, Amsterdam, Abenta, 423);
    game->getPhase()->addConnection(::iRunway, Berlin, Amsterdam, 570);
    game->getPhase()->addConnection(::iRunway, Berlin, Abenta, 385);
    game->getPhase()->addConnection(::iRunway, Dublin, Brussels, 843);
    game->getPhase()->addConnection(::iRunway, Paris, Brussels, 258);
    game->getPhase()->addConnection(::iRunway, Paris, Stuttgart, 508);
    game->getPhase()->addConnection(::iRunway, Toulouse, Stuttgart, 836);

    game->getPhase()->distributeTroopsAndVehicles(France);
    game->getPhase()->distributeTroopsAndVehicles(Ireland);
    game->getPhase()->distributeTroopsAndVehicles(UK);
    game->getPhase()->distributeTroopsAndVehicles(Belgium);
    game->getPhase()->distributeTroopsAndVehicles(Netherlands);
    game->getPhase()->distributeTroopsAndVehicles(Germany);
    game->getPhase()->distributeTroopsAndVehicles(Denmark);

    // cout << "here" << endl;
    // game->getPhase()->clone();

    // game->getPhase()->printAreaStatus(Lyon);
    // game->getPhase()->moveTroops(Lyon, France);
    // game->getPhase()->moveVehicles(Lyon, France);
    // game->getPhase()->printAreaStatus(Lyon);
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