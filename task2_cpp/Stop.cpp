#include "Stop.h"

#include <utility>
#include <iostream>

Stop::Stop(std::string name)
{
    this->name = name;
    this->waiting = *new std::queue<Passenger *>;
}

Stop::Stop(std::string name, std::queue<Passenger *> waiting)
{
    this->name = name;
    this->waiting = waiting;
}

void Stop::addToWaiting(Passenger *toAdd)
{
    this->waiting.push(toAdd);
}

Passenger *Stop::getNext()
{
    if (this->waiting.empty())
    {
        return nullptr;
    }
    Passenger * next = this->waiting.front();
    this->waiting.pop();
    return next;
}

std::string Stop::getName()
{
    return this->name;
}

void Stop::setName(std::string name)
{
    this->name = name;
}

std::queue<Passenger *> Stop::getWaiting()
{
    return waiting;
}

void Stop::setWaiting(std::queue<Passenger *> waiting)
{
    this->waiting = waiting;
}

Stop::~Stop()
{
    std::cout << "deleted stop" << std::endl;
}