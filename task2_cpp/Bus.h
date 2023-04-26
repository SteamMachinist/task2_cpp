#ifndef TASK2_CPP_BUS_H
#define TASK2_CPP_BUS_H

#include <string>
#include <list>

#include "Passenger.h"
#include "Route.h"

using namespace std;

class Route;
class Passenger;
class Stop;

class Bus
{
private:
    string id;
    Route *route;
    int totalSeats;
    list<Passenger *> passengers;
    Stop *location;

    void getOn();
    void getOff();

    friend ostream &operator<<(ostream &, const Bus &);

public:
    Bus(string id, Route *route, int seats);
    Bus(string id, Route *route, int seats, list<Passenger *> passengers);
    ~Bus();

    void driveToNextStop();
};


#endif //TASK2_CPP_BUS_H