#ifndef TASK2_CPP_PASSENGER_H
#define TASK2_CPP_PASSENGER_H

#include <string>
#include "Stop.h"

class Stop;

class Passenger
{
private:
    std::string name;
    Stop* destination;

public:
    Passenger();
    ~Passenger();
};

#endif //TASK2_CPP_PASSENGER_H
