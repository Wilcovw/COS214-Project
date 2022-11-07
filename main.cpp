#include "WarEngine.h"
#include <iostream>
#include <vector>
using namespace std;
void Phase2(WarEngine *game, string country);
void Phase3(WarEngine *game, string country);
void Phase4(WarEngine *game, string country);
void Phase5(WarEngine *game, string country);
void Phase6(WarEngine *game, string country);
void setOrange();
void setWhite();
void next()
{
    setOrange();
    std::cout << "Press enter to continue...";
    std::cin.get();
    std::cout << "\n";
    setWhite();
}

void populate(WarEngine *game, bool designMode)
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

    if (designMode)
    {
        cout << "Phase 1:" << endl;
        cout << "Tension between France and Germany are rising" << endl;
        cout << "Countries have started to create alliances between each other" << endl;
    }

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

    game->getPhase()->addRelationshipToRelationship("AllCountries", Red);
    game->getPhase()->addRelationshipToRelationship("AllCountries", Blue);

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

    if (designMode)
    {
        next();
        cout << endl;
        cout << "Phase 2:" << endl;
        cout << "Countries have started preparing for war..." << endl;
        cout << "They have began to add troops and vehilces to their respective militaries" << endl;
    }

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
    for (int i = 0; i < 60; i++)
    {
        game->getPhase()->addTroops(Wales, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, NorthernIreland);
    game->getPhase()->addInfrastructure(::iLandFactory, Scotland);
    game->getPhase()->addInfrastructure(::iAircraftFactory, London);
    game->getPhase()->addInfrastructure(::iAquaticFactory, London);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Wales);

    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(NorthernIreland, ::landVehicle);
    }
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addVehicles(London, ::aircraftVehicle);
    }
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addVehicles(Wales, ::aquaticVehicle);
        game->getPhase()->addVehicles(London, ::aquaticVehicle);
    }

    game->getPhase()->addInfrastructure(::iLandDevelopment, London);
    game->getPhase()->addInfrastructure(::iLandDevelopment, NorthernIreland);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, London);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Wales);
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, London);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, London);
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, London);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, London);
    game->getPhase()->upgradeVehiclesInArea(::aquaticVehicle, Wales);

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
    for (int i = 0; i < 1; i++)
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
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addVehicles(Cork, ::landVehicle);
    }
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addVehicles(Dublin, ::aircraftVehicle);
    }
    for (int i = 0; i < 15; i++)
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
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(Paris, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 80; i++)
    {
        game->getPhase()->addTroops(Paris, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Marseille);
    game->getPhase()->addTroops(Marseille, ::tNavy, ::theGenerals);
    for (int i = 0; i < 5; i++)
    {
        game->getPhase()->addTroops(Marseille, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 35; i++)
    {
        game->getPhase()->addTroops(Marseille, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Lille);
    game->getPhase()->addInfrastructure(::iGroundCamp, Paris);
    game->getPhase()->addTroops(Paris, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addTroops(Paris, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 60; i++)
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
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addVehicles(Nantes, ::landVehicle);
        game->getPhase()->addVehicles(Lyon, ::landVehicle);
        game->getPhase()->addVehicles(Strasbourg, ::landVehicle);
        game->getPhase()->addVehicles(Lille, ::landVehicle);
    }
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addVehicles(Paris, ::aircraftVehicle);
    }
    for (int i = 0; i < 10; i++)
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
    for (int i = 0; i < 50; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 100; i++)
    {
        game->getPhase()->addTroops(Berlin, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Munich);
    game->getPhase()->addTroops(Munich, ::tNavy, ::theGenerals);
    for (int i = 0; i < 25; i++)
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
    for (int i = 0; i < 40; i++)
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
    for (int i = 0; i < 20; i++)
    {
        game->getPhase()->addTroops(Amsterdam, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 30; i++)
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
    for (int i = 0; i < 40; i++)
    {
        game->getPhase()->addVehicles(Amsterdam, ::aquaticVehicle);
    }
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Amsterdam);
    game->getPhase()->addInfrastructure(::iLandDevelopment, Amsterdam);
    game->getPhase()->addInfrastructure(::iAquaticDevelopment, Amsterdam);
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Amsterdam);
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
    for (int i = 0; i < 4; i++)
    {
        game->getPhase()->addTroops(Abenta, ::tAirforce, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iNavyCamp, Copenhagen);
    game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theSpecialForces);
    }
    for (int i = 0; i < 4; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tNavy, ::theSoldiers);
    }
    game->getPhase()->addInfrastructure(::iGroundCamp, Copenhagen);
    game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theGenerals);
    for (int i = 0; i < 3; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theSpecialForces);
    }
    for (int i = 0; i < 4; i++)
    {
        game->getPhase()->addTroops(Copenhagen, ::tGroundTroops, ::theSoldiers);
    }

    game->getPhase()->addInfrastructure(::iLandFactory, Copenhagen);
    game->getPhase()->addInfrastructure(::iAircraftFactory, Abenta);
    game->getPhase()->addInfrastructure(::iAquaticFactory, Alborg);
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addVehicles(Copenhagen, ::landVehicle);
    }
    for (int i = 0; i < 10; i++)
    {
        game->getPhase()->addVehicles(Abenta, ::aircraftVehicle);
    }
    for (int i = 0; i < 10; i++)
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
    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addTroops(Brussels, ::tAirforce, ::theSpecialForces);
    }
    for (int i = 0; i < 20; i++)
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

    for (int i = 0; i < 15; i++)
    {
        game->getPhase()->addVehicles(Brussels, ::landVehicle);
    }
    for (int i = 0; i < 30; i++)
    {
        game->getPhase()->addVehicles(Brussels, ::aircraftVehicle);
    }
    game->getPhase()->addInfrastructure(::iLandDevelopment, Brussels);     //                                                   __
    game->getPhase()->addInfrastructure(::iAircraftDevelopment, Brussels); //                                                 <(o )___
    game->getPhase()->upgradeVehiclesInArea(::landVehicle, Brussels);      //                                                  ( ._> /
    game->getPhase()->upgradeVehiclesInArea(::aircraftVehicle, Brussels);  //                                                   `---'

    if (designMode)
    {
        next();
        cout << "Countries have started making routes between them." << endl;
        cout << "Some for supplies and support between countries, and other for WAR" << endl;
        cout << "They are now reay to start attacking..." << endl;
    }
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
}

// Create a memento an the current phase and then create and store a new phase in WarEngine
void newPhase(WarEngine *game)
{
    game->newWarPhase();
}

void setFontColor(int r, int g, int b)
{
    cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void setBlue()
{
    setFontColor(0, 0, 255);
}

void setWhite()
{
    setFontColor(255, 255, 255);
}

void setOrange()
{
    setFontColor(255, 160, 0);
}

void setGreen()
{
    setFontColor(0, 255, 0);
}

void setRed()
{
    setFontColor(255, 0, 0);
}

void setPurple()
{
    setFontColor(255, 0, 255);
}

void setCyan()
{
    setFontColor(0, 100, 100);
}

void printLine()
{
    setWhite();
    cout << "-----------------------------------------------------------" << endl;
}

void Phase6(WarEngine *game, string country)
{
    printLine();
    setBlue();
    cout << "Welcome to Phase 6: " << endl;
    setWhite();

    // newPhase(game);
    string enemy;
    if (country == "France")
    {
        enemy = "Germany";
    }
    else
    {
        enemy = "France";
    }

    if (!game->getPhase()->countryStillExists(country))
    {
        setRed();
        cout << "With your defeat, your arch enemy makes peace with everyone still at war" << endl;
        cout << "You lost the war" << endl;
        setWhite();
    }
    else if (!game->getPhase()->countryStillExists(enemy))
    {
        // if (country == "France")
        // {
        //     setCyan();
        //     game->getPhase()->sendBroadcast("Red", country, "We have defeated the enemy and dont need to attack any further");
        // }
        // else
        // {
        //     setCyan();
        //     game->getPhase()->sendBroadcast("Blue", country, "We have defeated the enemy and dont need to attack any further ");
        // }
        setGreen();
        cout << "With the defeat of your arch enemy you make peace with everyone still at war" << endl;
        cout << "You won the war" << endl;
        setWhite();
    }
    else
    {
        setGreen();
        game->getPhase()->sendBroadcast(enemy, country, "Let us put aside our differences so that our people may prosper");
        cout << "You and your enemy come to an arrangement and agreed to sign a peace treaty" << endl;
        setWhite();
    }
    printLine();
}

void Phase5(WarEngine *game, string country)
{
    printLine();
    setBlue();
    cout << "Welcome to  Phase 5: " << endl;
    setWhite();
    // newPhase(game);
    string enemy = "";
    if (country == "France")
    {
        enemy = "Germany";
    }
    else
    {
        enemy = "France";
    }

    int userWantsToAttack = 1;
    string input = "";
    while (userWantsToAttack == 1 || userWantsToAttack == 2)
    {
        if (!game->getPhase()->countryStillExists(country) || !game->getPhase()->countryStillExists(enemy))
        {
            userWantsToAttack = -1;
        }
        else
        {
            setOrange();
            cout << "You look at the state of your country and your enemies country and decide what to de next: \n"
                 << "1: Press the attack, but first prepare for the coming battles\n"
                 << "2: Press the attack, the enemy must be defeated\n"
                 << "3: The cost of war is too high, rather sign a peace treaty" << endl;
            setWhite();
            getline(std::cin, input);
            userWantsToAttack = stoi(input);
        }
        if (userWantsToAttack == 1)
        {
            if (!game->getPhase()->countryStillExists(country) || !game->getPhase()->countryStillExists(enemy))
            {
                userWantsToAttack = -1;
            }
            else
            {
                printLine();
                Phase2(game, country);
                Phase3(game, country);
                Phase4(game, country);
            }
        }
        else if (userWantsToAttack == 2)
        {
            if (!game->getPhase()->countryStillExists(country) || !game->getPhase()->countryStillExists(enemy))
            {
                userWantsToAttack = -1;
            }
            else
            {
                printLine();
                Phase3(game, country);
                Phase4(game, country);
            }
        }
        else if (userWantsToAttack == 3)
        {
        }
        else if (userWantsToAttack == -1)
        {
        }
        else
        {
            userWantsToAttack = 1;
            setRed();
            cout << "Choose 1, 2 or 3" << endl;
            setWhite();
        }
    }
    printLine();
}

void Phase4(WarEngine *game, string country)
{
    printLine();
    setBlue();
    cout << "Welcome to  Phase 4: " << endl;
    setWhite();
    // newPhase(game);
    if (game->getPhase()->countryStillExists(country))
    {
        cout << "Here is an update on your country after the latest battles: " << endl;
        printLine();
        setPurple();
        game->getPhase()->printCountryStatus(country, false);
        printLine();
        next();
    }
    if (country == "France")
    {
        if (game->getPhase()->countryStillExists("Germany"))
        {
            cout << "Here is an update on your enemies country after the latest battles: " << endl;
            printLine();
            setPurple();
            game->getPhase()->printCountryStatus("Germany", false);
            printLine();
            next();
        }
    }
    else
    {
        if (game->getPhase()->countryStillExists("France"))
        {
            cout << "Here is an update on your enemies country after the latest battles: " << endl;
            printLine();
            setPurple();
            game->getPhase()->printCountryStatus("France", false);
            printLine();
            next();
        }
    }
    printLine();
}

void Phase3(WarEngine *game, string country)
{
    printLine();
    setBlue();
    cout << "Welcome to Phase 3:" << endl;
    setWhite();
    // newPhase(game);

    vector<string> enemyNames;
    vector<string> enemyAreaNames;
    string choiceCountry = "";
    string choiceArea = "";
    string chosenEnemy = "";
    string chosenArea = "";
    int userWantsToattack = 1;
    int threeAttacksCounter = 0;
    int chC = 0;
    int numEnemies = -1;
    bool successfulAttack = false;
    bool enemyAttack = true;
    setOrange();
    cout << "Please choose a Country to attack: " << endl;
    setWhite();
    int i = 0;
    for (auto e : game->getPhase()->getCountryEnemies(country))
    {
        cout << ++i << ": " << e << endl;
        printLine();
        setPurple();
        game->getPhase()->printCountryStatus(e, false);
        printLine();
        enemyNames.push_back(e);
        numEnemies = enemyNames.size();
    }
    while (chC == 0)
    {
        getline(std::cin, choiceCountry);
        chC = stoi(choiceCountry);
        if (chC <= numEnemies && chC > 0)
        {
            chosenEnemy = enemyNames.at(chC - 1);
        }
        else
        {
            chC = 0;
            setRed();
            cout << "Please choose an integer between 1 and " << numEnemies << endl;
            setWhite();
        }
    }
    printLine();
    while (threeAttacksCounter < 3 && userWantsToattack == 1)
    {
        enemyAreaNames.clear();
        setOrange();
        cout << "Please choose an area in " << chosenEnemy << " to attack: " << endl;
        setWhite();
        int j = 0;
        for (auto a : game->getPhase()->getAttackableAreasInCountry(chosenEnemy, country))
        {
            cout << ++j << ": " << a << endl;
            enemyAreaNames.push_back(a);
        }
        int numEnemyAreas = enemyAreaNames.size();
        bool chooseArea = false;
        while (!chooseArea)
        {
            getline(std::cin, choiceCountry);
            int chA = stoi(choiceCountry);
            if (chA <= numEnemyAreas && chA > 0)
            {
                chooseArea = true;
                chosenArea = enemyAreaNames.at(chA - 1);
            }
            else
            {
                setRed();
                cout << "Please choose an integer between 1 and " << numEnemyAreas << endl;
                setWhite();
            }
        }
        successfulAttack = game->getPhase()->attackArea(chosenArea, country);
        threeAttacksCounter++;
        string input = "";
        if (successfulAttack)
        {
            if (game->getPhase()->countryStillExists(chosenEnemy))
            {
                if (threeAttacksCounter == 3)
                {
                    next();
                }
                else
                {
                    setOrange();
                    cout << "You have successfully attacked an area, would like to attack another one?\n"
                         << "1: Yes\n"
                         << "2: No" << endl;
                    setWhite();
                    getline(std::cin, input);
                    userWantsToattack = stoi(input);
                    printLine();
                }
            }
            else
            {
                setGreen();
                cout << "With the victory in the last area, you have conquered all the areas in the enemy country" << endl;
                next();
                userWantsToattack = -1;
                enemyAttack = false;
            }
        }
        else
        {

            if (game->getPhase()->countryStillExists(country))
            {
                setOrange();
                cout << "Unfortunately your attack was unsuccessful, what would you like to do now?\n"
                     << "(It looks like the area you are trying to attack is stronger than you, consider\n"
                     << " a different area or gathering your strength and slowly wearing dowwn its defenses)\n"
                     << "1: Return to the beginning of this phase and attack a different area\n"
                     << "2: Accept this defeat and prepare for the coming battles" << endl;
                setWhite();
                int in = 0;
                getline(std::cin, input);
                in = stoi(input);
                if (in == 1)
                {
                    game->reverseWarPhase();
                    Phase3(game, country);
                    enemyAttack = false;
                }
                userWantsToattack = 2;
                printLine();
            }
            else
            {
                setRed();
                cout << "With the Defeat of the last battle, you have been eliminated by your enemy" << endl;
                setWhite();
                userWantsToattack = -1;
                enemyAttack = false;
            }
        }
    }
    if (enemyAttack)
    {
        setRed();
        string area = game->getPhase()->getAttackableAreasInCountry(country, chosenEnemy).front();
        cout << "After you finished attacking, the enemy launched a counter attack on " << area << endl;
        game->getPhase()->attackArea(area, chosenEnemy);
        setWhite();
        next();
        printLine();
    }
}

void Phase2(WarEngine *game, string country)
{
    printLine();
    setBlue();
    cout << "Welcome to Phase 2:" << endl;
    setWhite();
    // newPhase(game);
    int threeCycles = 0;
    string choice = "";
    while (threeCycles < 3)
    {
        setOrange();
        cout << "Choose how to prepare for war:\n"
             << "1: Train more troops\n"
             << "2: Create more vehicles\n"
             << "3: Upgrade vehicles stationed at research facilities" << endl;
        setWhite();
        getline(std::cin, choice);
        if (choice.compare("1") == 0)
        {
            if (country.compare("France") == 0)
            {
                for (int i = 0; i < 10; i++)
                    game->getPhase()->addTroops("Paris", ::tGroundTroops, ::theSoldiers);
            }
            else
            {
                for (int i = 0; i < 10; i++)
                    game->getPhase()->addTroops("Berlin", ::tGroundTroops, ::theSoldiers);
            }
            threeCycles++;
            printLine();
        }
        else if (choice.compare("2") == 0)
        {
            if (country.compare("France") == 0)
            {
                for (int i = 0; i < 5; i++)
                    game->getPhase()->addVehicles("Nantes", ::landVehicle);
            }
            else
            {
                for (int i = 0; i < 10; i++)
                    game->getPhase()->addVehicles("Dusseldorf", ::landVehicle);
            }

            threeCycles++;
            printLine();
        }
        else if (choice.compare("3") == 0)
        {
            if (country.compare("France") == 0)
            {
                game->getPhase()->upgradeVehiclesInArea(::landVehicle, "Nantes");
            }
            else
            {
                game->getPhase()->upgradeVehiclesInArea(::landVehicle, "Dusseldorf");
            }
            threeCycles++;
            printLine();
        }
        else
        {
            setRed();
            cout << "Please choose option 1, 2 or 3" << endl;
            setWhite();
        }
    }
    game->getPhase()->distributeTroopsAndVehicles("Germany");
    game->getPhase()->distributeTroopsAndVehicles("France");
    printLine();
}

void realMode()
{
    WarEngine *game = new WarEngine();
    populate(game, false);

    newPhase(game);
    string country = "";
    string choice = "";
    setGreen();
    cout << "░▀▀█▀▀░█░░░░█▀▀░░░▒█▀▀█░█▀▀▄░█▀▀░█▀▀▄░▀█▀░░░▒█▀▀▀░█░▒█░█▀▀▄░▄▀▀▄░▄▀▀▄░█▀▀░░░▒█░░▒█░█▀▀▄░█▀▀▄" << endl;
    cout << "░░▒█░░░█▀▀█░█▀▀░░░▒█░▄▄░█▄▄▀░█▀▀░█▄▄█░░█░░░░▒█▀▀▀░█░▒█░█▄▄▀░█░░█░█▄▄█░█▀▀░░░▒█▒█▒█░█▄▄█░█▄▄▀" << endl;
    cout << "░░▒█░░░▀░░▀░▀▀▀░░░▒█▄▄▀░▀░▀▀░▀▀▀░▀░░▀░░▀░░░░▒█▄▄▄░░▀▀▀░▀░▀▀░░▀▀░░█░░░░▀▀▀░░░▒▀▄▀▄▀░▀░░▀░▀░▀▀" << endl;
    next();
    printLine();
    setBlue();
    cout << "Welcome to the Phase 1: " << endl;
    setOrange();
    cout << "Please choose a side in the war: \n"
         << "1: France \n";
    printLine();
    setPurple();
    game->getPhase()->printCountryStatus("France", false);
    printLine();
    setOrange();
    cout << "2: Germany" << endl;
    printLine();
    setPurple();
    game->getPhase()->printCountryStatus("Germany", false);
    setWhite();
    while (country.compare("") == 0)
    {
        getline(std::cin, choice);
        if (choice.compare("1") == 0)
        {
            setGreen();
            cout << "You have chosen France and are part of the red alliance\n";
            setRed();
            cout << "Germany has declared war as it prepares to create an empire" << endl;
            country = "France";
            printLine();
            setCyan();
            game->getPhase()->sendBroadcast("Blue", "France", "We are coming for you");
        }
        else if (choice.compare("2") == 0)
        {
            cout << "You have chosen Germany and are part of the blue alliance\n"
                 << "France has opposed you in your quest to enlarge you empire and must pay for their insolence" << endl;
            country = "Germany";
            printLine();
            setCyan();
            game->getPhase()->sendBroadcast("Red", "Germany", "We are coming for you");
        }
        else
        {
            setRed();
            cout << "Please choose side 1 or 2" << endl;
            setWhite();
        }
        choice = "";
    }
    printLine();

    int num = 0;

    Phase2(game, country);
    if (country.compare("France") == 0)
    {
        setRed();
        game->getPhase()->revolt(country);
        setWhite();
    }
    next();
    Phase3(game, country);
    Phase4(game, country);
    Phase5(game, country);
    Phase6(game, country);
}

void designMode()
{
    cout << "░▀▀█▀▀░█░░░░█▀▀░░░▒█▀▀█░█▀▀▄░█▀▀░█▀▀▄░▀█▀░░░▒█▀▀▀░█░▒█░█▀▀▄░▄▀▀▄░▄▀▀▄░█▀▀░░░▒█░░▒█░█▀▀▄░█▀▀▄" << endl;
    cout << "░░▒█░░░█▀▀█░█▀▀░░░▒█░▄▄░█▄▄▀░█▀▀░█▄▄█░░█░░░░▒█▀▀▀░█░▒█░█▄▄▀░█░░█░█▄▄█░█▀▀░░░▒█▒█▒█░█▄▄█░█▄▄▀" << endl;
    cout << "░░▒█░░░▀░░▀░▀▀▀░░░▒█▄▄▀░▀░▀▀░▀▀▀░▀░░▀░░▀░░░░▒█▄▄▄░░▀▀▀░▀░▀▀░░▀▀░░█░░░░▀▀▀░░░▒▀▄▀▄▀░▀░░▀░▀░▀▀" << endl;
    next();
    WarEngine *game = new WarEngine();
    populate(game, true);
    vector<string> enemyAreaNames;
    string country = "France";
    string chosenEnemy = "Munich";
    next();
    cout << "Phase 3:" << endl;
    game->getPhase()->attackArea("Berlin", "France");

    // for (auto a : game->getPhase()->getAttackableAreasInCountry(chosenEnemy, country))
    // {
    //     // cout << ++j << ": " << a << endl;
    //     enemyAreaNames.push_back(a);
    // }
    // successfulAttack = game->getPhase()->attackArea(enemyAreaNames.front(), country);

    // game->getPhase()->attackArea();

    if (game->getPhase()->countryStillExists(chosenEnemy))
    {
        cout << "France has successfully attacked berlin \n";
        next();
    }
    else
    {
        cout << "With the victory in berlin France has conquered all the areas in Germany" << endl;
        next();
    }
    game->getPhase()->attackArea("Bremen", "Denmark");
}

int main()
{
    realMode();
    // designMode();
    //  WarEngine *game = new WarEngine();
    //  populate(game);
    return 0;
}
