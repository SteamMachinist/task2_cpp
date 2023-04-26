#ifndef TASK2_CPP_ROUTE_H
#define TASK2_CPP_ROUTE_H

#include "Stop.h"

using namespace std;

class Stop;

class Route
{
private:
    friend ostream &operator<<(ostream &ostream, const Route &route){ return route.toString(ostream); };

protected:
    virtual ostream &toString(ostream &ostream) const = 0;

public:
    virtual ~Route() = default;
    virtual list<Stop *> stopsList() = 0;
    virtual Stop *next() = 0;
};


#endif //TASK2_CPP_ROUTE_H