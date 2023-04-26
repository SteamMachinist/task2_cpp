#ifndef TASK2_CPP_LINEARROUTE_H
#define TASK2_CPP_LINEARROUTE_H

#include "Route.h"

using namespace std;

class LinearRoute : public Route
{
private:
    list<Stop *> stops;
    list<Stop *>::iterator iterator;
    int increment;

    virtual ostream &toString(ostream &ostream) const override;

public:
    LinearRoute(list<Stop *> stops);
    ~LinearRoute() override;

    list<Stop *> stopsList() override;
    Stop *next() override;
};


#endif //TASK2_CPP_LINEARROUTE_H