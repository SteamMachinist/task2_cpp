#ifndef TASK2_CPP_ROUTE_H
#define TASK2_CPP_ROUTE_H

#include "Stop.h"

class Route
{
public:
    virtual Stop next() = 0;
};


#endif //TASK2_CPP_ROUTE_H
