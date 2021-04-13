/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Consumer
*/

#include "Consumer.hpp"
#include "ScopedLock.hpp"

std::shared_ptr<Plazza::IMutex> mutexSh1 = std::make_shared<Plazza::AMutex>();

int Plazza::Consumer::consume(Plazza::ISafeQueue *q, int id)
{
    Plazza::ScopedLock lock(mutexSh1);
    int value = 0;

    if (!q) {
        printf("Empty queue!\n");
        return 0;
    }
    value = q->pop();
    printf("[Thread Consumer %d]: I Consume the %d value!\n", id, value);
    return 0;
}

Plazza::Consumer::Consumer(ISafeQueue &queue, int id): _queue(queue), _thread(std::make_shared<Thread>(consume, &queue, id))
{
    _id = id;
    printf("Thread Consumer %d created!\n", _id);
}