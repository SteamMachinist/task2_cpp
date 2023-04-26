#include "CircularRoute.h"

#include <iostream>

CircularRoute::CircularRoute(list<Stop *> stops)
{
    this->stops = stops;
    this->iterator = this->stops.begin();
}

CircularRoute::~CircularRoute()
{}

list<Stop *> CircularRoute::stopsList()
{
    return this->stops;
}

Stop *CircularRoute::next()
{
    Stop *stop = *iterator;
    this->iterator = std::next(this->iterator) == this->stops.end() ? this->stops.begin() : std::next(this->iterator);
    return stop;
}

ostream &CircularRoute::toString(ostream &ostream) const
{
    ostream << "CircularRoute(stops: ";
    for (auto it = this->stops.begin(); it != this->stops.end();)
    {
        ostream << (*it)->getName();
        it++;
        if (it != this->stops.end())
        {
            ostream << " -> ";
        }
        else
        {
            break;
        }
    }
    ostream << ")";
    return ostream;
}
