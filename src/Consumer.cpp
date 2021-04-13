/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Consumer
*/

#include "Consumer.hpp"
#include "ScopedLock.hpp"

std::shared_ptr<Plazza::IMutex> mutexSh1 = std::make_shared<Plazza::AMutex>();


void *consume(void *queue)
{
    Plazza::ScopedLock lock(mutexSh1);
    Plazza::ISafeQueue *q = (Plazza::ISafeQueue *)(queue);
    int value = 0;

    if (!q) {
        printf("Empty queue!\n");
        return nullptr;
    }
    while (1) {
        if (!q->tryPop(value)) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        } else
            printf("I Consume the %d value!\n", value);
    }
    return nullptr;
}

Plazza::Consumer::Consumer(ISafeQueue &queue): _queue(queue), _thread(std::make_shared<Thread>(consume, &queue))
{
}

void Plazza::Consumer::startConsuming()
{
    _thread->run();
}