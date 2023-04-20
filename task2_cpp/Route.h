#ifndef TASK2_CPP_ROUTE_H
#define TASK2_CPP_ROUTE_H

#include "Stop.h"

using namespace std;

class Stop;

class Route
{
public:
    virtual ~Route() = 0;
    virtual list<Stop *> stopsList() = 0;
    virtual Stop *next() = 0;
};


#endif //TASK2_CPP_ROUTE_H