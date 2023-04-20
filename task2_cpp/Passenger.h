#ifndef TASK2_CPP_PASSENGER_H
#define TASK2_CPP_PASSENGER_H

#include <string>
#include "Stop.h"

using namespace std;

class Stop;

class Passenger
{
private:
    string name;
    Stop *destination;

    friend ostream &operator<<(ostream &, const Passenger &);

public:
    Passenger(string name, Stop *destination);
    ~Passenger();

    bool isAtDestination(Stop *destination);

    string getName();
    void setName(string name);
    Stop *getDestination();
    void setDestination(Stop *destination);
};

#endif //TASK2_CPP_PASSENGER_H