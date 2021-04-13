/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Producer
*/

#include "Producer.hpp"
#include "ScopedLock.hpp"

std::shared_ptr<Plazza::IMutex> mutexSh = std::make_shared<Plazza::AMutex>();

int Plazza::Producer::produce(Plazza::ISafeQueue *q, int id)
{
    Plazza::ScopedLock lock(mutexSh);
    int value = rand() % 10;

    if (!q) {
        printf("Empty queue!\n");
        return 0;
    }
    value = rand() % 10;
    q->push(value);
    q->getConditionVariable().notify_all();
    printf("[Thread Producer %d]: I produce the %d value!\n", id, value);
    return 0;
}

Plazza::Producer::Producer(ISafeQueue &queue, int id): _queue(queue), _thread(std::make_shared<Thread>(produce, &queue, id))
{
    _id = id;
    printf("Thread Producer %d created!\n", _id);
}