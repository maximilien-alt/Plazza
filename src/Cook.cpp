/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();

void cook(Plazza::ISafeQueue *queue, bool &isCooking, int timeMultiplier)
{
    Plazza::ScopedLock lock(mutex);
    int time = 0;

    isCooking = false;
    std::cout << "Trying to pop a pizza from the queue" << std::endl;
    Plazza::Pizza pizza = queue->pop();
    isCooking = true;
    std::cout << "I'm cooking this pizza: " << pizza;
    switch (pizza.getType()) {
        case Plazza::Margarita: time = 1;
            break;
        case Plazza::Regina: time = 2;
            break;
        case Plazza::Americana: time = 2;
            break;
        case Plazza::Fantasia: time = 4;
            break;
        default: break;
    }
    std::this_thread::sleep_for(std::chrono::seconds(time * timeMultiplier));
    return;
}

Plazza::Cook::Cook(ISafeQueue &queue, int multiplier): _isCooking(0), _thread(new std::thread(cook, &queue, std::ref(_isCooking), multiplier))
{
}

bool Plazza::Cook::isCooking() const
{
    return _isCooking;
}

void Plazza::Cook::updateThreads()
{
    _thread->join();
}