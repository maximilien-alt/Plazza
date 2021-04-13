/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Producer
*/

#include "Producer.hpp"
#include "ScopedLock.hpp"

std::shared_ptr<Plazza::IMutex> mutexSh = std::make_shared<Plazza::AMutex>();

void *produce(void *queue)
{
    Plazza::ScopedLock lock(mutexSh);
    Plazza::ISafeQueue *q = (Plazza::ISafeQueue *)(queue);
    int value = rand() % 10;

    if (!q) {
        printf("Empty queue!\n");
        return nullptr;
    }
    while (1) {
        value = rand() % 10;
        q->push(value);
        printf("I produce the %d value!\n", value);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return nullptr;
}

Plazza::Producer::Producer(ISafeQueue &queue): _queue(queue), _thread(std::make_shared<Thread>(produce, &queue))
{
}

void Plazza::Producer::startProducing()
{
    _thread->run();
}