#ifndef TASK2_CPP_STOP_H
#define TASK2_CPP_STOP_H

#include <string>
#include <list>
#include "Passenger.h"

using namespace std;

class Passenger;

class Stop
{
private:
    string name;
    list<Passenger *> waiting;

    friend ostream &operator<<(ostream &ostream, const Stop &stop);

public:
    explicit Stop(string name);
    Stop(string name, list<Passenger *>);
    ~Stop();

    void addToWaiting(Passenger *toAdd);
    Passenger *getNextPassengerFor(list<Stop *> goingToList);

    string getName();
    void setName(string name);
    list<Passenger *> getWaiting();
    void setWaiting(list<Passenger *> waiting);
};

#endif //TASK2_CPP_STOP_H