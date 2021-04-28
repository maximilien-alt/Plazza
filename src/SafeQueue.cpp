/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

void Plazza::SafeQueue::push(std::shared_ptr<Plazza::APizza> value)
{
    std::lock_guard<std::mutex> guard(_queue_mutex);
    std::cout << "Adding the " << value.get()->getPizzaId() << "th pizza from the " << value.get()->getOrderId() << "th order to the queue!" << std::endl;
    _queue.push(value);
}

int Plazza::SafeQueue::getSize() const
{
    if (_queue.empty())
        return 0;
    return _queue.size();
}

std::shared_ptr<Plazza::APizza> Plazza::SafeQueue::pop()
{
    std::unique_lock<std::mutex> guard(_queue_mutex);

    while (_queue.empty())
        _cv.wait(guard);
   std::shared_ptr<Plazza::APizza> value = _queue.front();
    _queue.pop();
    return value;
}

std::condition_variable &Plazza::SafeQueue::getConditionVariable()
{
    return (_cv);
}