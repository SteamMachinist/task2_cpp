#ifndef TASK2_CPP_STOP_H
#define TASK2_CPP_STOP_H

#include <string>
#include <queue>
#include "Passenger.h"

class Passenger;

class Stop
{
private:
    std::string name;
    std::queue<Passenger*> waiting;

public:
    Stop(std::string name);
    Stop(std::string name, std::queue<Passenger *>);
    ~Stop();
    void addToWaiting(Passenger *toAdd);
    Passenger *getNext();
    std::string getName();
    void setName(std::string name);
    std::queue<Passenger *> getWaiting();
    void setWaiting(std::queue<Passenger *> waiting);
};

#endif //TASK2_CPP_STOP_H
