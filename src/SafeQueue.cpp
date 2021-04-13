/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

void Plazza::SafeQueue::push(int value)
{
    std::lock_guard<std::mutex> guard(_queue_mutex);
    _queue.push(value);
}

bool Plazza::SafeQueue::tryPop(int &value)
{
    std::lock_guard<std::mutex> guard(_queue_mutex);
    if (_queue.empty())
        return 0;
    value = _queue.front();
    _queue.pop();
    return 1;
}