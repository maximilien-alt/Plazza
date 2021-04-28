/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../include/include.hpp"
#include "Pizza.hpp"
#include "Thread.hpp"
#include "AMutex.hpp"
#include "ISafeQueue.hpp"
#include "ScopedLock.hpp"

namespace Plazza {
    class Cook {
        public:
            Cook(ISafeQueue &, int);
            ~Cook() = default;

            bool isCooking() const;
            bool isRunning() const;
            void updateThreads();

        private:
            bool _isCooking;
            bool _isRunning;
            std::thread *_thread;
    };
}

#endif /* !COOK_HPP_ */