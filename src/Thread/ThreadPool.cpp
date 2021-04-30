/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

Plazza::ThreadPool::ThreadPool(const int &number): _threadsNumber(number)
{
    for (int index = 0; index < number; index += 1)
        _threads.push_back(Plazza::Thread());
}

Plazza::ThreadPool::~ThreadPool()
{
}

void Plazza::ThreadPool::addPizza(APizza &toAdd)
{
    _safeQueue.push(toAdd);
}

void Plazza::ThreadPool::run()
{
    for (auto &n: _threads) {
        if (_safeQueue.empty())
            break;
        if (n.getStatus() == Plazza::Thread::NOTRUNNING) {
            auto pizza = _safeQueue.tryPop();
            if (pizza) {
                n.run(pizza);
                continue;
            }
            auto wpizza = _safeQueue.waitAndPop();
            n.run(wpizza);
        }
    }
}

size_t Plazza::ThreadPool::getQueueSize() const
{
    return _safeQueue.getSize();
}

std::vector<Plazza::Thread::STATUS> Plazza::ThreadPool::getThreadsStatus() const
{
    std::vector<Plazza::Thread::STATUS> vector;

    for (auto &n: _threads)
        vector.push_back(n.getStatus());
    return vector;
}