#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "WarEngine.h"
#include "WarMap.h"
#include "Factory.h"
#include "AircraftFactory.h"
#include "AquaticVehicleFactory.h"
#include "LandVehicleFactory.h"
#include "AquaticVehicles.h"
#include "LandVehicles.h"
#include "Aircraft.h"
#include "Country.h"
#include "Troops.h"
#include "GroundTroops.h"
#include "Navy.h"
#include "Airforce.h"
#include "Soldiers.h"
#include "Citizens.h"
#include "Status.h"
#include "Stationed.h"
#include "Dead.h"
#include "AreaIterator.h"
#include "ResearchAndDevelopmentCentre.h"
#include "LandVehicleDevelopment.h"
#include "Navy.h"
#include "SpecialForces.h"
#include "Fighting.h"
#include "doctest.h"
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

void isAccessible(Area *a1, Area *a2, WarMap *graph);
void isAccessible(Area *a1, Area *a2, WarMap *graph, string type);
WarMap *graph = nullptr;
WarEngine *game = nullptr;
// Countries
string UK = "United Kingdom";
string Ireland = "Ireland";
string France = "France";
string Germany = "Germany";
string Netherlands = "Netherlands";
string Denmark = "Denmark";
string Belgium = "Belgium";

// Populate areas of UK
string Scotland = "Scotland";
string London = "London";
string NorthernIreland = "Northern Ireland";
string Wales = "Wales";

// Populate areas of Ireland
string Dublin = "Dublin";
string Cork = "Cork";
string Limerick = "Limerick";
string Galway = "Galway";

// Populate areas of France
string Paris = "Paris";
string Nantes = "Nantes";
string Toulouse = "Toulouse";
string Marseille = "Marseille";
string Lille = "Lille";
string Strasbourg = "Strasbourg";
string Lyon = "Lyon";

// Populate areas of Germany
string Berlin = "Berlin";
string Bremen = "Bremen";
string Hannover = "Hannover";
string Dusseldorf = "Dusseldorf";
string Stuttgart = "Stuttgart";
string Munich = "Munich";
// Populate areas of Belgium
string Brussels = "Brussels";
list<Country *> redTeam;
void populate(WarEngine *game)
{
	// Teams
	string Blue = "Blue";
	string Red = "Red";

	game->getPhase()->addCountry(UK, 673);
	game->getPhase()->addCountry(Ireland, 50);
	game->getPhase()->addCountry(France, 675);
	game->getPhase()->addCountry(Germany, 831);
	game->getPhase()->addCountry(Netherlands, 175);
	game->getPhase()->addCountry(Denmark, 58);
	game->getPhase()->addCountry(Belgium, 116);

	game->getPhase()->addRelationship("All countries");
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
	game->getPhase()->addInfrastructure(::iNavyCamp, London);
	game->getPhase()->addInfrastructure(::iGroundCamp, London);
	game->getPhase()->addInfrastructure(::iGroundCamp, Wales);

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
	game->getPhase()->addInfrastructure(::iNavyCamp, Dublin);
	game->getPhase()->addInfrastructure(::iGroundCamp, Dublin);
	game->getPhase()->addInfrastructure(::iGroundCamp, Limerick);

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
	game->getPhase()->addInfrastructure(::iNavyCamp, Marseille);
	game->getPhase()->addInfrastructure(::iGroundCamp, Lille);
	game->getPhase()->addInfrastructure(::iGroundCamp, Paris);

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
	game->getPhase()->addInfrastructure(::iNavyCamp, Munich);
	game->getPhase()->addInfrastructure(::iGroundCamp, Berlin);
	game->getPhase()->addInfrastructure(::iGroundCamp, Stuttgart);

	// Populate areas of Netherlands
	string Amsterdam = "Amsterdam";
	game->getPhase()->addArea(Amsterdam, Netherlands);
	game->getPhase()->addConnection(::iRoad, Amsterdam, Hannover, 320);
	game->getPhase()->addConnection(::iRoad, Amsterdam, Bremen, 278);
	game->getPhase()->addConnection(::iRoad, Amsterdam, Dusseldorf, 165);
	game->getPhase()->addInfrastructure(::iHarbour, Amsterdam);
	game->getPhase()->addInfrastructure(::iRunway, Amsterdam);
	game->getPhase()->addInfrastructure(::iAirforceCamp, London);
	game->getPhase()->addInfrastructure(::iNavyCamp, London);
	game->getPhase()->addInfrastructure(::iGroundCamp, London);
	game->getPhase()->addInfrastructure(::iGroundCamp, Wales);

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

	game->getPhase()->addArea(Brussels, Belgium);
	game->getPhase()->addConnection(::iRoad, Brussels, Amsterdam, 175);
	game->getPhase()->addConnection(::iRoad, Brussels, Lille, 93);
	game->getPhase()->addConnection(::iRoad, Brussels, Dusseldorf, 176);
	game->getPhase()->addInfrastructure(::iRunway, Brussels);

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
	game->getPhase()->addConnection(::iRunway, Amsterdam, Stuttgart, 501);
}
LandVehicleFactory *vechileFactory = nullptr;
AquaticVehicleFactory *aquaticFactory = nullptr;
Vehicles *car = nullptr, *car2 = nullptr, *sumarine = nullptr;

Citizens *citizensGroup = nullptr;
void TroopTestingWithStatus()
{
	citizensGroup = new Citizens();
}
void finalMain()
{
	game = new WarEngine();
	populate(game);
}

int main(int argc, char **argv)
{
	cout << "=============================Start testing=============================" << endl;
	// cout << "Troops Success!" << endl;
	// testMap();
	// testMemento();
	// showcasing();
	finalMain();
	graph = game->getPhase()->map;

	TroopTestingWithStatus();
	cout << "=============================End testing===============================" << endl;
	return doctest::Context(argc, argv).run();
}

void isAccessible(Area *a1, Area *a2, WarMap *graph)
{
	cout << "You " << (graph->isAccessible(a1, a2) == true ? "CAN " : "CANNOT ") << "get from " << a1->getName() << " to " << a2->getName() << endl;
}

void isAccessible(Area *a1, Area *a2, WarMap *graph, string type)
{
	cout << "You " << (graph->isAccessible(a1, a2, type) == true ? "CAN " : "CANNOT ") << "get from " << a1->getName() << " to " << a2->getName() << " via " << type << endl;
}

TEST_CASE("Testing if one Area is accessible from another")
{
	CHECK(graph->isAccessible(graph->getArea(Paris), graph->getArea(Nantes)) == true);
	CHECK(graph->isAccessible(graph->getArea(Marseille), graph->getArea(Nantes), "Harbour") == false);
	CHECK(graph->isAccessible(graph->getArea(Dublin), graph->getArea(Scotland), "Runway") == true);
	CHECK(graph->isAccessible(graph->getArea(Paris), graph->getArea(Berlin), "Runway") == true);
}

TEST_CASE("Testing the shortest Path algorithm")
{
	SUBCASE("Via Road")
	{
		list<Area *> path3 = graph->shortestPath(graph->getArea(Marseille), graph->getArea(Brussels), "Road");
		list<Area *>::iterator it = path3.begin();
		CHECK(path3.size() == 5);
		CHECK(*it == graph->getArea(Marseille));
		it++;
		CHECK(*it == graph->getArea(Lyon));
		it++;
		CHECK(*it == graph->getArea(Paris));
		it++;
		CHECK(*it == graph->getArea(Lille));
		it++;
		CHECK(*it == graph->getArea(Brussels));
	}
	SUBCASE("Via Runway")
	{
		list<Area *> path4 = graph->shortestPath(graph->getArea(Munich), graph->getArea(London), "Runway");
		list<Area *>::iterator it = path4.begin();
		CHECK(path4.size() == 4);
		CHECK(*it == graph->getArea(Munich));
		it++;
		CHECK(*it == graph->getArea(Stuttgart));
		it++;
		CHECK(*it == graph->getArea(Brussels));
		it++;
		CHECK(*it == graph->getArea(London));
		it++;
	}
}

TEST_CASE("Testing if a Country still exsists")
{
	CHECK(game->getPhase()->countryStillExists("United Kingdom") == true);
	CHECK(game->getPhase()->countryStillExists("Ireland") == true);
	CHECK(game->getPhase()->countryStillExists("France") == true);
	CHECK(game->getPhase()->countryStillExists("England") == false);
}

TEST_CASE("Factory Pattern Getters")
{
	vechileFactory = new LandVehicleFactory(100, graph->getArea(France));
	car = vechileFactory->createVehicle(10, 20, 30);
	aquaticFactory = new AquaticVehicleFactory(200, graph->getArea(UK));
	sumarine = aquaticFactory->createVehicle(50, 60, 70);
	sumarine->changeLocation(graph->getArea(Germany));

	CHECK(car->getHP() == 10);
	CHECK(car->getDamage() == 20);
	CHECK(car->getSpeed() == 30);
	CHECK(sumarine->getLocation() == graph->getArea(Germany));
	CHECK(sumarine->getHP() == 50);
}

TEST_CASE("Factory Pattern Location")
{
	CHECK(sumarine->getLocation() == graph->getArea(Germany));
}

TEST_CASE("Testing the composite pattern")
{
	redTeam = graph->getArea("Paris")->getControllingCountry()->getAllies();
	CHECK(find(redTeam.begin(), redTeam.end(), graph->getArea("Copenhagen")->getControllingCountry()) != redTeam.end());
	CHECK(find(redTeam.begin(), redTeam.end(), graph->getArea("Amsterdam")->getControllingCountry()) == redTeam.end());
	CHECK(graph->getArea("Amsterdam")->getControllingCountry()->getParent() != graph->getArea("Limerick")->getControllingCountry());
	CHECK(graph->getArea("Limerick")->getControllingCountry()->getParent() != graph->getArea("Brussels")->getControllingCountry());
}

TEST_CASE("Testing the Bridge design pattern")
{
	Troops *groundTroop = nullptr;
	groundTroop = new GroundTroops(graph->getArea(Stuttgart), new Soldiers(), graph->getArea(Stuttgart)->getControllingCountry()->getCitizens()[0]);
	groundTroop->takeDamage(10);
	CHECK(groundTroop->getKind() == tGroundTroops);
	CHECK(groundTroop->getType()->getType() == theSoldiers);
	CHECK(groundTroop->getDamage() == 4);
	CHECK(groundTroop->getHP() == 10);
	SUBCASE("Testing Loction of Troops")
	{
		CHECK(groundTroop->getLocation() == graph->getArea(Stuttgart));
	}

	CHECK(groundTroop->getDamage() == 4);
	CHECK(vechileFactory->getHP() == 100);
	groundTroop->attack(vechileFactory);
	CHECK(vechileFactory->getHP() == 0);
	//Creating navTroops of type special Special Forces
	Troops *navyTroops = nullptr;
	navyTroops = new Navy(graph->getArea(Berlin), new SpecialForces(), graph->getArea(Stuttgart)->getControllingCountry()->getCitizens()[0]);
	CHECK(navyTroops->getKind() == tNavy);
	CHECK(navyTroops->getType()->getType() == theSpecialForces);

}
string unlisted = "Unlisted";
string enlisted = "Enlisted";
string stationed = "Stationed";
string dead = "Dead";
string fighting = "Fighting";
TEST_CASE("Testing the State the design pattern")
{
	CHECK(citizensGroup->getStatus() == unlisted);
	citizensGroup->changeStatus();
	CHECK(citizensGroup->getStatus() == enlisted);
	citizensGroup->setStatus(new Stationed());
	CHECK(citizensGroup->getStatus() == stationed);
	citizensGroup->setStatus(new Dead());
	CHECK(citizensGroup->getStatus() == dead);
	citizensGroup->setStatus(new Fighting());
	CHECK(citizensGroup->getStatus() == fighting);
}

TEST_CASE("Testing the Iterator design pattern")
{
	AreaIterator *areaIter = graph->createAreaIterator();
	areaIter->first();
	list<Area *> allAreas;
	while (areaIter->isDone() == false)
	{
		Area *currentArea = areaIter->currentItem();
		allAreas.push_back(currentArea);

		areaIter->next();
	}
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Scotland)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(London)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(NorthernIreland)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Wales)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Dublin)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Cork)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Limerick)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Galway)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Paris)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Nantes)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Toulouse)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Marseille)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Lille)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Strasbourg)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Lyon)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Berlin)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Bremen)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Hannover)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Dusseldorf)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Stuttgart)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Munich)) != allAreas.end());
	CHECK(find(allAreas.begin(), allAreas.end(), graph->getArea(Brussels)) != allAreas.end());
}

TEST_CASE("Testing Mediator design pattern for sending Messages across Countries")
{
	cout << "=================Sending a message from UK to France================" << endl;
	string message = "Move all remaining troops to England";
	game->getPhase()->getCountry(UK)->sendBroadcast(game->getPhase()->getCountry(France), message);
	CHECK(game->getPhase()->getCountry(France)->recivedMessage == message);
	string message2 = "No idea what message to do";
	game->getPhase()->getCountry(Germany)->sendBroadcast(game->getPhase()->getCountry(Denmark), message2);
	CHECK(game->getPhase()->getCountry(Denmark)->recivedMessage == message2);
}

TEST_CASE("Testing Mediator design pattern for sending Messages across Associated Countries")
{
	cout << "=================Sending a message to ALL Blue Countries================" << endl;
	string message = "This is a message to all the Countries";
	game->getPhase()->getCountry(Germany)->sendBroadcast(game->getPhase()->getCountry(Germany)->getParent(), message);
	CHECK(game->getPhase()->getCountry(Germany)->recivedMessage == message);
	CHECK(game->getPhase()->getCountry(Netherlands)->recivedMessage == message);
	CHECK(game->getPhase()->getCountry(Belgium)->recivedMessage == message);
	CHECK(game->getPhase()->getCountry(Ireland)->recivedMessage == message);
}

TEST_CASE("Testing all the Observer Pattern")
{
	cout << "==========Testing the ResearchAndDevelopmentCentre============="<< endl;
	LandVehicles *landCar = new LandVehicles(graph->getArea(Munich), 25,25,25);
	LandVehicles *landCar2 = new LandVehicles(graph->getArea(Munich), 30,30,30);
	CHECK(landCar->getDamage() == 25);
	CHECK(landCar->getHP() == 25);
	CHECK(landCar->getSpeed() == 25);
	ResearchAndDevelopmentCentre *vechleCentre = new LandVehicleDevelopment(1000,graph->getArea(Munich));
	landCar->readyToUpgrade(vechleCentre);
	landCar2->readyToUpgrade(vechleCentre);
	vechleCentre->notifyDevelop();
	CHECK(landCar->getDamage() == 27);
	CHECK(landCar->getHP() == 30);
	CHECK(landCar->getSpeed() == 30);
	CHECK(landCar2->getDamage() == 32);
	CHECK(landCar2->getHP() == 35);
	CHECK(landCar2->getSpeed() == 35);
}

// TEST_CASE("Testing memento"){
// 	cout << "Hello" << endl;
// 	game->newWarPhase();
// 	game->getPhase()->addArea("Test",France);
// 	cout << "Hello" << endl;
// 	game->reverseWarPhase();
// 	CHECK(graph->getArea("Test") == nullptr);
// 	cout << "Hello" << endl;
// 	game->newWarPhase();
// 	game->getPhase()->addArea("Test1",France);
// 	cout << "Hello" << endl;
// 	game->newWarPhase();
// 	game->getPhase()->addArea("Test2",France);
// 	game->reverseWarPhase();
// 	game->reverseWarPhase();
// 	CHECK(graph->getArea("Test1") == nullptr);
// 	CHECK(graph->getArea("Test2") == nullptr);
// }