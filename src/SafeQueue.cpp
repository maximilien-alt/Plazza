/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

void Plazza::SafeQueue::push(Plazza::Pizza value)
{
    std::lock_guard<std::mutex> guard(_queue_mutex);
    _queue.push(value);
}

int Plazza::SafeQueue::getSize() const
{
    if (_queue.empty())
        return 0;
    return _queue.size();
}

bool Plazza::SafeQueue::tryPop(Plazza::Pizza &value)
{
    std::lock_guard<std::mutex> guard(_queue_mutex);
    if (_queue.empty())
        return 0;
    value = _queue.front();
    _queue.pop();
    return 1;
}

Plazza::Pizza Plazza::SafeQueue::pop()
{
    std::unique_lock<std::mutex> guard(_queue_mutex);

    if (_queue.empty())
        _cv.wait(guard);
    Plazza::Pizza value = _queue.front();
    _queue.pop();
    return value;
}

std::condition_variable &Plazza::SafeQueue::getConditionVariable()
{
    return (_cv);
}