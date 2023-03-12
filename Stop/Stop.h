//
// Created by rando on 09.03.2023.
//

#ifndef TASK2_CPP_STOP_H
#define TASK2_CPP_STOP_H

#include <string>

class Stop
{
    private:
        std::string name;

    public:
        Stop(std::string name);

        const std::string &getName() const;

        void setName(const std::string &name);
};


#endif //TASK2_CPP_STOP_H
