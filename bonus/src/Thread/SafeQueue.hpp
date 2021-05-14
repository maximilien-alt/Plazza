/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
#define SAFEQUEUE_HPP_

#include "../../include/include.hpp"
#include "../Kitchens/Fridge.hpp"
#include "../Pizzas/APizza.hpp"

namespace Plazza {
    typedef struct working_item_s
    {
        Fridge *fridge;
        APizza pizza;
        int kitchenFd;
    } working_item_t;

    template<typename T>
    class SafeQueue {
        public:
            explicit SafeQueue() = default;
            explicit SafeQueue(const SafeQueue &other)
            {
                _queue = other._queue;
            };

            SafeQueue &operator=(const SafeQueue &other) = delete;
            ~SafeQueue() = default;

            void push(T value)
            {
                _queue.push(value);
            };

            void waitAndPop(T &value)
            {
                value = _queue.front();
                _queue.pop();
            };

            std::shared_ptr<T> waitAndPop()
            {
                std::shared_ptr<T> result = std::make_shared<T>(_queue.front());
                _queue.pop();
                return result;
            };

            bool tryPop(T &value)
            {
                if (_queue.empty())
                    return false;
                value = _queue.front();
                _queue.pop();
                return true;
            };

            std::shared_ptr<T> tryPop()
            {
                _mutex.lock();
                if (_queue.empty())
                    return nullptr;
                std::shared_ptr<T> result = std::make_shared<T>(_queue.front());
                _queue.pop();
                _mutex.unlock();
                return result;
            };

            bool empty() const
            {
                return _queue.empty();
            }

            size_t getSize() const
            {
                return _queue.size();
            }

        private:
            mutable std::mutex _mutex;
            std::queue<T> _queue;
    };
}

#endif /* !SAFEQUEUE_HPP_ */