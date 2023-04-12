cmake_minimum_required(VERSION 3.24)
project(task2_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(task2_cpp main.cpp Bus.cpp Bus.h Passenger.cpp Passenger.h Stop.cpp Stop.h Route.h CircularRoute.cpp CircularRoute.h CircularRoute.h LinearRoute.cpp LinearRoute.h)
