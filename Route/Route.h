//
// Created by rando on 09.03.2023.
//

#ifndef TASK2_CPP_ROUTE_H
#define TASK2_CPP_ROUTE_H

#include <list>
#include "../Stop/Stop.h"

class Route
{
    private:
        std::list<Stop> stops;

    public:
        Stop next();
};


#endif //TASK2_CPP_ROUTE_H
