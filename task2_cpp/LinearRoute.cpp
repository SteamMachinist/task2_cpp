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
    //simple
    //return this->stops;

    //direction-on-route-wise
    auto currentIterator = this->iterator;
    list<Stop *> goingToList = *new list<Stop *>;

    if(this->increment == 1)
    {
        while(currentIterator != this->stops.end())
        {
            goingToList.push_back(*currentIterator);
            advance(currentIterator, this->increment);
        }
    }
    else
    {
        while(currentIterator != this->stops.begin())
        {
            goingToList.push_back(*currentIterator);
            advance(currentIterator, this->increment);
        }
        goingToList.push_back(*currentIterator);
    }
    return goingToList;
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
    ostream << "LinearRoute(stops: ";
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
