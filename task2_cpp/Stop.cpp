#include "Stop.h"

#include <iostream>

Stop::Stop(string name)
{
    this->name = name;
    this->waiting = *new list<Passenger *>;
}

Stop::Stop(string name, list<Passenger *> waiting)
{
    this->name = name;
    this->waiting = waiting;
}

Stop::~Stop()
{
    for (Passenger *&passenger: this->waiting)
    {
        delete passenger;
    }
    cout << "deleted stop" << endl;
}

void Stop::addToWaiting(Passenger *toAdd)
{
    this->waiting.push_back(toAdd);
}

Passenger *Stop::getNextPassengerFor(list<Stop *> goingToList)
{
    Passenger *next = nullptr;
    if (this->waiting.empty())
    {
        return next;
    }
    for (Passenger *passenger: this->waiting)
    {
        for (Stop *stop: goingToList)
        {
            if (passenger->isAtDestination(stop))
            {
                next = passenger;
                this->waiting.remove(passenger);
                return next;
            }
        }
    }
    return next;
}

string Stop::getName()
{
    return this->name;
}

void Stop::setName(string name)
{
    this->name = name;
}

list<Passenger *> Stop::getWaiting()
{
    return this->waiting;
}

void Stop::setWaiting(list<Passenger *> waiting)
{
    this->waiting = waiting;
}

ostream &operator<<(ostream &ostream, const Stop &stop)
{
    ostream << "Stop\n(";
    ostream << "\n" << std::string(4, ' ') << "name: " << stop.name << ",";
    ostream << "\n" << std::string(4, ' ') << "waiting passengers:";
    for (Passenger *passenger: stop.waiting)
    {
        ostream << "\n" << std::string(4, ' ') << *passenger;
    }
    ostream << ",\n)";
    return ostream;
}
