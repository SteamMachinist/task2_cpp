//
// Created by rando on 09.03.2023.
//

#ifndef TASK2_CPP_STOP_H
#define TASK2_CPP_STOP_H

#include <string>
#include <list>
#include "../Passenger/Passenger.h"

class Stop
{
    private:
        std::string name;
        std::list<Passenger> waiting;

    public:
        Stop(std::string name);

        ~Stop();

        Stop(std::string name, std::list<Passenger>);

        void addToWaiting(Passenger toAdd);

        //list

        std::string getName();

        void setName(std::string name);

        std::list<Passenger> getWaiting();

        void setWaiting(std::list<Passenger> waiting);
};


#endif //TASK2_CPP_STOP_H
