/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Consumer
*/

#ifndef CONSUMER_HPP_
#define CONSUMER_HPP_

#include "Thread.hpp"
#include "ISafeQueue.hpp"
#include "../include/include.hpp"

namespace Plazza {
    class Consumer {
        public:
            Consumer(ISafeQueue &queue, int);
            ~Consumer() = default;

            static int consume(Plazza::ISafeQueue *q, int);

        private:
            ISafeQueue &_queue;
            std::shared_ptr<Plazza::Thread> _thread;
            int _id;
    };
}

#endif /* !CONSUMER_HPP_ */
