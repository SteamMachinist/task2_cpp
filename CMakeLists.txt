cmake_minimum_required(VERSION 3.24)
project(task2_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(task2_cpp task2_cpp/main.cpp task2_cpp/Bus.cpp task2_cpp/Bus.h task2_cpp/Passenger.cpp task2_cpp/Passenger.h task2_cpp/Stop.cpp task2_cpp/Stop.h task2_cpp/Route.h task2_cpp/CircularRoute.cpp task2_cpp/CircularRoute.h task2_cpp/CircularRoute.h task2_cpp/LinearRoute.cpp task2_cpp/LinearRoute.h)
