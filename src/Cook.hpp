/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../include/include.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include "SafeQueue.hpp"

namespace Plazza {
    class Cook {
        public:
            Cook(ISafeQueue &, int, bool *);
            ~Cook();

            bool isCooking() const;
            static int startCooking(Plazza::ISafeQueue *q, int, bool *);

        private:
            ISafeQueue &_queue;
            bool *_isCooking;
            int _timeMultiplier;
            std::shared_ptr<Plazza::Thread> _thread;

    };
}

#endif /* !COOK_HPP_ */