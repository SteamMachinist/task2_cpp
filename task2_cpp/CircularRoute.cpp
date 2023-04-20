#include "CircularRoute.h"

CircularRoute::CircularRoute(list<Stop *> stops)
{
    this->stops = stops;
    auto it = stops.end();

    it--;

    it._Ptr->_Next = stops.begin()._Ptr; // Next Node of the last elemen is now first elemen of the List
    stops.begin()._Ptr->_Prev = it._Ptr;
}

list<Stop *> CircularRoute::stopsList()
{
    return this->stops;
}
