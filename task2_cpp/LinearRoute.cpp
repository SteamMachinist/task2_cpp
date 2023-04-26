#include "LinearRoute.h"

#include <iostream>

LinearRoute::LinearRoute(list<Stop *> stops)
{
    this->stops = stops;
    this->iterator = this->stops.begin();
}

LinearRoute::~LinearRoute()
{}

list<Stop *> LinearRoute::stopsList()
{
    return this->stops;
}

Stop *LinearRoute::next()
{
    Stop *stop = *iterator;
    if (this->iterator == this->stops.begin())
    {
        this->increment = 1;
    }
    advance(this->iterator, this->increment);
    if (this->iterator == this->stops.end())
    {
        this->increment = -1;
        advance(this->iterator, this->increment * 2);
    }
    return stop;
}

ostream &LinearRoute::toString(ostream &ostream) const
{
    ostream << "LinearRoute\n(";
    ostream << "\n" << std::string(4, ' ') << "stops:";
    for (Stop *stop : this->stops)
    {
        ostream << "\n" << std::string(4, ' ') << stop->getName();
    }
    ostream << "\n)";
    return ostream;
}
