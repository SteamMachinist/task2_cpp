#include "Bus.h"

#include <iostream>

Bus::Bus(string id, Route *route, int seats)
{
    this->id = id;
    this->route = route;
    this->totalSeats = seats;
    this->passengers = *new list<Passenger *>;
    this->location = nullptr;
}

Bus::Bus(string id, Route *route, int seats, list<Passenger *> passengers)
{
    this->id = id;
    this->route = route;
    this->totalSeats = seats;
    this->passengers = passengers;
    this->location = nullptr;
}

Bus::~Bus()
{
    for (Passenger *&passenger: this->passengers)
    {
        delete passenger;
    }
    delete this->route;
    cout << "deleted bus" << endl;
}

void Bus::driveToNextStop()
{
    this->location = route->next();
    getOff();
    getOn();
}

void Bus::getOff()
{
    if (this->passengers.empty())
    {
        return;
    }

    for (auto i = this->passengers.begin(); i != this->passengers.end();)
    {
        Passenger* passenger = *i;
        if (passenger->isAtDestination(this->location))
        {
            i = this->passengers.erase(i);
            delete *i;
        }
        else
        {
            ++i;
        }
    }
}

void Bus::getOn()
{
    Passenger* nextPassenger = location->getNextPassengerFor(this->route->stopsList());
    while (nextPassenger != nullptr && this->totalSeats > passengers.size())
    {
        this->passengers.push_back(nextPassenger);
        nextPassenger = location->getNextPassengerFor(this->route->stopsList());
    }
}

ostream &operator<<(ostream &ostream, const Bus &bus)
{
    ostream << "Bus\n(";
    ostream << "\n" << std::string(4, ' ') << "id: " << bus.id;
    string locationString = ((bus.location == nullptr) ? "not on route" : bus.location->getName());
    ostream << "\n" << std::string(4, ' ') << "location: " << locationString;
    ostream << "\n"  << "route: " << *bus.route;
    ostream << "\n" << std::string(4, ' ') << "seats occupied/total: " << bus.passengers.size() << "/" << bus.totalSeats;
    ostream << "\n" << "passengers:\n";
    for (Passenger *passenger: bus.passengers)
    {
        ostream << std::string(8, ' ') << *passenger << "\n";
    }
    ostream << ")";
    return ostream;
}


