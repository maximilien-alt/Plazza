/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ISafeQueue
*/

#ifndef ISAFEQUEUE_HPP_
#define ISAFEQUEUE_HPP_

#include "../include/include.hpp"
#include "Pizza.hpp"

namespace Plazza {
    class Order;
    class Cook;
    class ISafeQueue {
        public:
            virtual ~ISafeQueue() = default;
            virtual void push(Plazza::Pizza value) = 0;
            virtual bool tryPop(Plazza::Pizza &value) = 0;
            virtual Plazza::Pizza pop() = 0;
            virtual std::condition_variable &getConditionVariable() = 0;
            virtual int getSize() const = 0;
    };
}

#endif /* !ISAFEQUEUE_HPP_ */