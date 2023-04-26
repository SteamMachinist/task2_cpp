#include "Passenger.h"

#include <iostream>

Passenger::Passenger(string name, Stop *destination)
{
    this->name = name;
    this->destination = destination;
}

Passenger::~Passenger()
{
    cout << "Deleted " << *this << endl;
}

bool Passenger::isAtDestination(Stop *destination)
{
    return destination == this->destination;
}

string Passenger::getName()
{
    return this->name;
}

void Passenger::setName(string name)
{
    this->name = name;
}

Stop *Passenger::getDestination()
{
    return destination;
}

void Passenger::setDestination(Stop *destination)
{
    this->destination = destination;
}

ostream &operator<<(ostream &ostream, const Passenger &passenger)
{
    return ostream << "Passenger (name: " << passenger.name << ", destination: " << passenger.destination->getName() << ")";
}
