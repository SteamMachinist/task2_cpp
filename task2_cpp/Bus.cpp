#include "Bus.h"

#include <iostream>

Bus::Bus(string id, Route *route, int seats)
{
    this->id = id;
    this->route = route;
    this->totalSeats = seats;
    this->passengers = *new list<Passenger *>;
}

Bus::Bus(string id, Route *route, int seats, list<Passenger *> passengers)
{
    this->id = id;
    this->route = route;
    this->totalSeats = seats;
    this->passengers = passengers;
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

}

ostream &operator<<(ostream &ostream, const Bus &bus)
{
    ostream << "Bus\n(";
    ostream << "\n" << std::string(4, ' ') << "id: " << bus.id;
    ostream << "\n" << std::string(4, ' ') << "location: " << bus.location->getName();

//    ostream << "\n" << std::string(4, ' ') << "route:\n";
//    for (Passenger *passenger: stop.waiting)
//    {
//        ostream << std::string(8, ' ') << *passenger << "\n";
//    }

    ostream << "\n" << std::string(4, ' ') << "seats occupied/total: " << bus.passengers.size() << "/" << bus.totalSeats;
    ostream << "\n" << std::string(4, ' ') << "passengers:\n";
    for (Passenger *passenger: bus.passengers)
    {
        ostream << std::string(8, ' ') << *passenger << "\n";
    }
    ostream << ")";
    return ostream;
}