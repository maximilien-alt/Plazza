/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "../Pizzas/APizza.hpp"

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
        void run(std::shared_ptr<Plazza::APizza> pizza);
        STATUS getStatus() const;

    private:
        Plazza::APizza *_pizza;
        pthread_t _thread;
        STATUS _status;

        static void *execute(void *);
    };
}

#endif /* !THREAD_HPP_ */
