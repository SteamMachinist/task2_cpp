cmake_minimum_required(VERSION 3.24)
project(task2_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(task2_cpp main.cpp Bus/Bus.cpp Bus/Bus.h Passenger/Passenger.cpp Passenger/Passenger.h Stop/Stop.cpp Stop/Stop.h Route/Route.cpp Route/Route.h)
