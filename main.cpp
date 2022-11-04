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
    game->addInfrastructure(::iNavyCamp, London);
    game->addInfrastructure(::iGroundCamp, London);
    game->addInfrastructure(::iGroundCamp, Wales);

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
    game->addInfrastructure(::iNavyCamp, Dublin);
    game->addInfrastructure(::iGroundCamp, Dublin);
    game->addInfrastructure(::iGroundCamp, Limerick);

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
    game->addInfrastructure(::iNavyCamp, Marseille);
    game->addInfrastructure(::iGroundCamp, Lille);
    game->addInfrastructure(::iGroundCamp, Paris);


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
    game->addInfrastructure(::iNavyCamp, Munich);
    game->addInfrastructure(::iGroundCamp, Berlin);
    game->addInfrastructure(::iGroundCamp, Stuttgart);


    // Populate areas of Netherlands
    string Amsterdam = "Amsterdam";
    game->addArea(Amsterdam, Netherlands);
    game->addConnection(::iRoad, Amsterdam, Hannover, 320);
    game->addConnection(::iRoad, Amsterdam, Bremen, 278);
    game->addConnection(::iRoad, Amsterdam, Dusseldorf, 165);
    game->addInfrastructure(::iHarbour, Amsterdam);
    game->addInfrastructure(::iRunway, Amsterdam);
    game->addInfrastructure(::iAirforceCamp, London);
    game->addInfrastructure(::iNavyCamp, London);
    game->addInfrastructure(::iGroundCamp, London);
    game->addInfrastructure(::iGroundCamp, Wales);


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


    // Populate areas of Belgium
    string Brussels = "Brussels";
    game->addArea(Brussels, Belgium);
    game->addConnection(::iRoad, Brussels, Amsterdam, 175);
    game->addConnection(::iRoad, Brussels, Lille, 93);
    game->addConnection(::iRoad, Brussels, Dusseldorf, 176);
    game->addInfrastructure(::iRunway, Brussels);


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

    //Add connection to runways
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
    game->addConnection(::iRunway, Amsterdam, Stuttgart, 501);






    


    


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
//jasonIsDum    cout << "=============================End testing===============================" << endl;
    return 0;
}