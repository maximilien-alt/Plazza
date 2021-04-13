/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
#define SAFEQUEUE_HPP_

#include "ISafeQueue.hpp"
#include <queue>

namespace Plazza {
    class SafeQueue: public ISafeQueue {
        public:
            SafeQueue() = default;
            ~SafeQueue() = default;

            void push(int) final;
            bool tryPop(int &) final;

        private:
            std::queue<int> _queue;
    };
}

#endif /* !SAFEQUEUE_HPP_ */
