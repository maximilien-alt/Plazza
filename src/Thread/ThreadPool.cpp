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

void Plazza::ThreadPool::addItem(Plazza::working_item_t &toAdd)
{
    _safeQueue.push(toAdd);
}

void Plazza::ThreadPool::run()
{
    for (auto &n: _threads) {
        if (_safeQueue.empty()) {
            break;
        }
        if (n.getStatus() == Plazza::Thread::NOTRUNNING) {
            auto item = _safeQueue.tryPop();
            if (item && item.get()->fridge->canCook(item.get()->pizza)) {
                n.run(item);
            } else
                _safeQueue.push(*item.get());
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