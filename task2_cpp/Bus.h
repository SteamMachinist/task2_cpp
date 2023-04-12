//
// Created by rando on 09.03.2023.
//

#ifndef TASK2_CPP_BUS_H
#define TASK2_CPP_BUS_H

#include <string>
#include <list>
#include "Route.h"
#include "Passenger.h"

class Bus
{
private:
    std::string id;
    //Route route;
    std::list<Passenger> passengers;
};


#endif //TASK2_CPP_BUS_H
