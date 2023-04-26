/*
 * 3. Маршрутное такси. Маршрутное такси движется по маршруту, который представляет собой остановки,
 * соединенные прямыми линиями. Такси движется от начальной остановки к конечной и обратно и так множество раз.
 * Такси имеет определенную вместимость. На остановках находятся пассажиры (экземпляры классов), которым надо
 * попасть на определенную остановку. Такси останавливается на остановках, если есть свободные места
 * или пассажиры, которым на этой остановке надо выходить и которые, соответственно, выходят. Пассажиры,
 * которые стоят на остановках, садятся в такси, если оно движется в нужном направлении, в порядке очередности
 * их появления на остановке. Задача заключается в моделировании движения такси. Необходимо предусмотреть
 * возможность построения маршрута и добавления/удаления пассажиров на каждую остановку с заданием целевой
 * остановки для каждого пассажира.
 */

#include <iostream>
#include <map>
#include <chrono>
#include <random>
#include <cmath>

#include "Stop.h"
#include "Route.h"
#include "CircularRoute.h"
#include "LinearRoute.h"
#include "Bus.h"

using namespace std;


int generateRandomPassengers(int ordinal, double chance, vector<Stop *> stops, map<Stop*, vector<Stop *>> possibleDestinations)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib1(1, round(1 / chance));


    for(Stop *stop : stops)
    {
        unsigned int rnd = distrib1(gen);
        if (rnd == 1)
        {
            vector<Stop *> allowed = possibleDestinations[stop];
            std::uniform_int_distribution<unsigned> distrib2(0, allowed.size() - 1);
            Passenger *passenger = new Passenger("name" + to_string(ordinal), allowed[distrib2(gen)]);
            cout << "Generated new " << *passenger << " at stop " << stop->getName() << endl;
            stop->addToWaiting(passenger);
            ordinal++;
        }
    }
    return ordinal;
}


int main()
{
    /*        (bus0)
     *          0
     *          |      (bus2)
     *          1        8--
     *          |        | |
     *(bus1) 4--2--5--6--7 |
     *          |        | |
     *          3        9--
     */

    vector<Stop *> stops = *new vector<Stop *>(10);
    for (int i = 0; i < 10; i++)
    {
        stops[i] = new Stop(to_string(i));
    }

    Route *route0 = new LinearRoute(*new list<Stop *> ({stops[0], stops[1], stops[2], stops[3]}));
    Route *route1 = new LinearRoute(*new list<Stop *> ({stops[4], stops[2], stops[5], stops[6], stops[7]}));
    Route *route2 = new CircularRoute(*new list<Stop *> ({stops[7], stops[8], stops[9]}));

    map<Stop *, vector<Stop *>> destinations = *new map<Stop *, vector<Stop *>>();
    destinations[stops[0]] = *new vector<Stop *>({stops[1], stops[2], stops[3]});
    destinations[stops[1]] = *new vector<Stop *>({stops[0], stops[2], stops[3]});
    destinations[stops[2]] = *new vector<Stop *>({stops[0], stops[1], stops[3], stops[4], stops[5], stops[6], stops[7]});
    destinations[stops[3]] = *new vector<Stop *>({stops[0], stops[1], stops[2]});
    destinations[stops[4]] = *new vector<Stop *>({stops[2], stops[5], stops[6], stops[7]});
    destinations[stops[5]] = *new vector<Stop *>({stops[4], stops[2], stops[6], stops[7]});
    destinations[stops[6]] = *new vector<Stop *>({stops[4], stops[2], stops[5], stops[7]});
    destinations[stops[7]] = *new vector<Stop *>({stops[4], stops[2], stops[5], stops[6], stops[8], stops[9]});
    destinations[stops[8]] = *new vector<Stop *>({stops[7], stops[9]});
    destinations[stops[9]] = *new vector<Stop *>({stops[7], stops[8]});

    list<Bus *> busses = *new list<Bus *>({
        new Bus("bus0", route0, 3),
        new Bus("bus1", route1, 3),
        new Bus("bus2", route2, 3)});

    for (Bus *bus : busses)
    {
        cout << endl << *bus << endl;
    }
    int ordinal = 0;
    while(true)
    {
        cin.ignore();
        cout << endl << "Tick" << endl;

        for (Bus *bus : busses)
        {
            cout << endl << *bus << endl;
        }
        for (Bus *bus : busses)
        {
            bus->driveToNextStop();
        }
        ordinal = generateRandomPassengers(ordinal, 0.1, stops, destinations);
    }
    return 0;
}
