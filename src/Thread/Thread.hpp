/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "../Pizzas/APizza.hpp"
#include "../Kitchens/Fridge.hpp"
#include "SafeQueue.hpp"
#include "ScopedLock.hpp"
#include "IMutex.hpp"

namespace Plazza
{
    class Thread
    {
    public:
        enum STATUS
        {
            NOTRUNNING,
            RUNNING,
            DEAD
        };

        Thread();
        ~Thread();

        void kill();
        void join();
        void run(std::shared_ptr<working_item_t>);
        STATUS getStatus() const;

    private:
        std::shared_ptr<working_item_t> _item;
        pthread_t _thread;
        STATUS _status;

        static void *execute(void *);
    };
}

#endif /* !THREAD_HPP_ */
