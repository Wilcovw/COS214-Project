#include "Citizens.h"

Citizens::Citizens()
{
    // cout << "Citizens constructor called" << endl;
    this->status = new Unlisted();
    this->toggleCommand = new RevolutionCommand(false);
}

Citizens::~Citizens()
{
    // cout << "Citizens destructor called" << endl;
    delete status;
    
    status = 0;
}

void Citizens::setStatus(Status *status)
{
    // cout << "setStatus called" << endl;
    if (this->status != nullptr)
    {
        delete this->status;
        this->status = nullptr;
    }
    this->status = status;
}

void Citizens::changeStatus()
{
    this->status->handleChange(this);
}

string Citizens::getStatus()
{
    string stat = "Unlisted";
    try
    {
        if (this->status != nullptr)
        stat = this->status->getStatus();
    }
    catch(const exception& e)
    {
        return stat;
    }
    catch(...){
        return stat;
    }
    return stat;




    // if (this->status == NULL)
    // {
    //     cout << "Made it here" << endl;
    //     this->status = new Unlisted();
    // }
    // // this->status = new Unlisted();
    // return this->status->getStatus();
}

void Citizens::die()
{
    status->die(this);
}

void Citizens::toggleRevolution()
{
    if (this->getStatus() == "Unlisted")
    {
        this->toggleCommand->execute();
    }
    else
    {
        if (this->toggleCommand->isActive())
        {
            this->toggleCommand->execute();
        }
        else
        {
            this->setStatus(new Unlisted());
            this->toggleCommand->execute();
        }
    }
}

Citizens *Citizens::clone()
{
    Citizens *citizen = nullptr;
    if (getStatus() == "Unlisted")
    {
        citizen = new Citizens();
        citizen->setStatus(new Unlisted());
    }
    else if (getStatus() == "Dead")
    {
        citizen = new Citizens();
        citizen->setStatus(new Dead());
    }
    return citizen;
}