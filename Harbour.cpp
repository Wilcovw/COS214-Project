#include "Harbour.h";

#include <vector>

Harbour::Harbour(Area *destination, string name){
    srand(time(0));
    int distance = (rand() % 10) + 1;
    this->name = name;

    Edge *connectedHarbour = new Edge(distance, name, "Road", this->location, destination);
};
