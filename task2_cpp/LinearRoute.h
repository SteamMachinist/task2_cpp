#ifndef TASK2_CPP_LINEARROUTE_H
#define TASK2_CPP_LINEARROUTE_H

#include "Route.h"

using namespace std;

class LinearRoute : public Route
{
private:

public:
    LinearRoute();
    LinearRoute(list<Stop *> stops);

    list<Stop *> stopsList() override;
    Stop *next() override;


};


#endif //TASK2_CPP_LINEARROUTE_H