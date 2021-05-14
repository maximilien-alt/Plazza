/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include "../Kitchens/Cook.hpp"

namespace Plazza {
    class Kitchen;
    class ThreadPool {
        public:
            ThreadPool(const int &, void (*finish)(void *, Plazza::APizza), Plazza::Kitchen *);
            ~ThreadPool();

            void addItem(working_item_t &);
            void run();
            size_t getQueueSize() const;
            std::vector<Plazza::Cook::STATUS> getThreadsStatus() const;
            bool areTheyWorking();
            void killThreads();

        private:
            size_t _threadsNumber;
            std::vector<std::shared_ptr<Plazza::Cook>> _threads;
            SafeQueue<working_item_t> _safeQueue;

    };
}

#endif /* !THREADPOOL_HPP_ */