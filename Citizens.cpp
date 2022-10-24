#include "Citizens.h"

Citizens::Citizens() {
    cout << "Citizen constructor called" << endl;
    status = new Unlisted();
}

Citizens::~Citizens() {
    cout << "Citizens destructor called!" << endl;
    delete status;
    status = NULL;
}

void Citizens::setStatus(Status *status) {
    cout << "Citizens' setState called." << endl;
    delete this->status;
    this->status = status;
}

void Citizens::changeStatus() {
    status->handleChange(this);
}

Status* Citizens::getStatus() {
    return this->status;
}

int Citizens::getNumberCitizens() {
    return this->numberCitizens;
}