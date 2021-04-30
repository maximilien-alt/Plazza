/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include "Thread.hpp"
#include "SafeQueue.hpp"

namespace Plazza {
    class ThreadPool {
        public:
            ThreadPool(const int &);
            ~ThreadPool();

            void addPizza(APizza &);
            void run();
            size_t getQueueSize() const;
            std::vector<Plazza::Thread::STATUS> getThreadsStatus() const;

        private:
            size_t _threadsNumber;
            std::vector<Thread> _threads;
            SafeQueue<APizza> _safeQueue;

    };
}

#endif /* !THREADPOOL_HPP_ */