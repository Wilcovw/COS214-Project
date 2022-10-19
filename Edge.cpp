#include "Edge.h"


Edge::Edge(double v, string name, string type, Area* s, Area* d) {
    this->distance = v;
	this->name = name;
	this->type = type;
	this->destination = d;
	this->source = s;
}

Edge::~Edge() {
    
}

Area* Edge::getSource() {
    return this->source;
}

Area* Edge::getDestination() {
    return this->destination;
}

string Edge::getType() {
    return this->type;
}
