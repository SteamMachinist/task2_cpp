//
// Created by rando on 09.03.2023.
//

#include "Stop.h"

#include <utility>

Stop::Stop(std::string name)
{
    this->name = name;
    this->waiting = *new std::list<Passenger>;
}

Stop::Stop(std::string name, std::list<Passenger> waiting)
{
    this->name = name;
    this->waiting = waiting;
}

std::string Stop::getName()
{
    return this->name;
}

void Stop::setName(std::string name)
{
    this->name = name;
}

std::list<Passenger> Stop::getWaiting() {
    return waiting;
}

void Stop::setWaiting(std::list<Passenger> waiting) {
    this->waiting = waiting;
}

void Stop::addToWaiting(Passenger toAdd) {
    this->waiting.push_back(toAdd);
}

Stop::~Stop() {

}
