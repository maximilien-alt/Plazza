/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Producer
*/

#ifndef PRODUCER_HPP_
#define PRODUCER_HPP_

#include "Thread.hpp"
#include "ISafeQueue.hpp"
#include "../include/include.hpp"

namespace Plazza {
    class Producer {
        public:
            Producer(ISafeQueue &queue, int);
            ~Producer() = default;

            static int produce(Plazza::ISafeQueue *q, int);

        private:
            ISafeQueue &_queue;
            std::shared_ptr<Plazza::Thread> _thread;
            int _id;
    };
}

#endif /* !PRODUCER_HPP_ */
