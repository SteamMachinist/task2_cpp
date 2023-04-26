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
#include "Stop.h"
#include "Route.h"
#include "CircularRoute.h"
#include "LinearRoute.h"
#include "Bus.h"

using namespace std;

int main()
{
    Stop *stop1 = new Stop("1");
    Stop *stop2 = new Stop("2");
    Stop *stop3 = new Stop("3");
    Stop *stop4 = new Stop("4");
    stop1->addToWaiting(new Passenger("name1", stop2));
    stop1->addToWaiting(new Passenger("name2", stop3));
    stop1->addToWaiting(new Passenger("name3", stop4));
    stop3->addToWaiting(new Passenger("name4", stop4));
    stop3->addToWaiting(new Passenger("name5", stop4));

    Route *route = new LinearRoute(*new list<Stop *> ({stop1, stop2, stop3, stop4}));

    Bus *bus = new Bus("bus1", route, 2);
    while(true)
    {
        cout << endl << endl << *bus << endl << endl;
        bus->driveToNextStop();
        if (std::cin.get() == '\n') {}
    }

//    cout << endl << endl << *bus << endl << endl;
//    bus->driveToNextStop();
//    cout << endl << endl << *bus << endl << endl;
//    bus->driveToNextStop();
//    cout << endl << endl << *bus << endl << endl;
//    bus->driveToNextStop();
//    cout << endl << endl << *bus << endl << endl;
    return 0;
}
