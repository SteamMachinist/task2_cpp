//
// Created by rando on 09.03.2023.
//

#include "Stop.h"

#include <utility>

const std::string &Stop::getName() const
{
    return name;
}

void Stop::setName(const std::string &name)
{
    Stop::name = name;
}

Stop::Stop(std::string name)
{
    this->name = std::move(name);
}
