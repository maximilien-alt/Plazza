/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();

Plazza::Cook::Cook(ISafeQueue &queue, int time, bool *isCooking): _queue(queue), _isCooking(isCooking), _timeMultiplier(time), _thread(std::make_shared<Thread>(startCooking, &queue, time, isCooking))
{
}

Plazza::Cook::~Cook()
{
}

int Plazza::Cook::startCooking(Plazza::ISafeQueue *q, int timeMultiplier, bool *isCooking)
{
    Plazza::ScopedLock lock(mutex);
    //*isCooking = 0;
    int time = 0;

    if (!q)
        return (0);
    Plazza::Pizza pizza = q->pop();
    std::cout << "I'm cooking this pizza: " << pizza;
    //*isCooking = 1;
    switch (pizza.getType())
    {
    case Margarita:
        time = 1;
        break;
    case Regina:
        time = 2;
        break;
    case Americana:
        time = 2;
        break;
    case Fantasia:
        time = 4;
        break;
    default:
        break;
    }
    time *= timeMultiplier;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    return (startCooking(q, timeMultiplier, isCooking));
}

bool Plazza::Cook::isCooking() const
{
    return *_isCooking;
}