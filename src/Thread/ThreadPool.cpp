/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

Plazza::ThreadPool::ThreadPool(const int &number): _threadsNumber(number)
{
    for (int index = 0; index < number; index += 1) {
        std::shared_ptr<Plazza::Cook> cook = std::make_shared<Plazza::Cook>();
        _threads.push_back(cook);
        std::thread thread(&Plazza::Cook::run, cook.get());
        thread.detach();
    }
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
        if (n->getStatus() == Plazza::Cook::WAITING) {
            auto item = _safeQueue.tryPop();
            if (item && item->fridge->canCook(item.get()->pizza)) {
                n->startCooking(item);
            } else
                _safeQueue.push(*item.get());
        }
    }
}

bool Plazza::ThreadPool::areTheyWorking()
{
    for (auto &n: _threads)
        if (n->getStatus() == Plazza::Cook::COOKING)
            return true;
    return !(_safeQueue.getSize() == 0);
}

size_t Plazza::ThreadPool::getQueueSize() const
{
    return _safeQueue.getSize();
}

std::vector<Plazza::Cook::STATUS> Plazza::ThreadPool::getThreadsStatus() const
{
    std::vector<Plazza::Cook::STATUS> vector;

    for (auto &n: _threads)
        vector.push_back(n->getStatus());
    return vector;
}

void Plazza::ThreadPool::killThreads()
{
    for (auto &n: _threads)
        n->autoDestruct();
}