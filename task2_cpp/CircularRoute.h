#ifndef TASK2_CPP_CIRCULARROUTE_H
#define TASK2_CPP_CIRCULARROUTE_H

#include "Route.h"

using namespace std;

class CircularRoute : public Route
{
private:
    list<Stop *> stops;
    list<Stop *>::iterator iterator;

    ostream & toString(ostream &ostream) const override;

public:
    CircularRoute(list<Stop *> stops);
    ~CircularRoute() override;

    list<Stop *> stopsList() override;
    Stop *next() override;
};


#endif //TASK2_CPP_CIRCULARROUTE_H