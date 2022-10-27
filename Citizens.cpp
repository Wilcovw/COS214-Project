#include "Citizens.h"

Citizens::Citizens() {
    cout << "Citizens constructor called" << endl;
    this->status = new Unlisted();
}

Citizens::~Citizens() {
    cout << "Citizens destructor called" << endl;
    delete status;
    status = 0;
}

void Citizens::setStatus(Status* status) {
    cout << "setStatus called" << endl;
    delete this->status;
    this->status = status;
}

void Citizens::changeStatus() {
    this->status->handleChange(this);
}

string Citizens::getStatus() {
    return this->status->getStatus();
}