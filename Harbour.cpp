// #include "Harbour.h"

// #include <vector>

// Harbour::Harbour(Area *destination, string name){
//     addConnection(destination,name);
// };

// void Harbour::addConnection(Area *destination, string name){
//     srand(time(0));
//     double distance = (rand() % 100) + 10;

//     Edge *connectedHarbour = new Edge(distance, name, "Harbour", this->location, destination);
//     connectedHarbours.push_back(*connectedHarbour);
//     this->location->addEdge(connectedHarbour);

//     Edge *flippedConnectedHarbour = new Edge(distance, name, "Harbour", destination, this->location);
//     destination->addEdge(flippedConnectedHarbour);
// };