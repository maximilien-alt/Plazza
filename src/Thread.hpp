/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "../include/include.hpp"

using method_ptr_t = void *(*)(void *);

namespace Plazza
{
    class Thread
    {
    public:
        enum STATUS
        {
            STARTED,
            RUNNING,
            DEAD
        };
        Thread(method_ptr_t start, void *args = nullptr);

        ~Thread();

        void run();

        void cancel();

        STATUS getCurrentStatus() const;

    private:
        STATUS _status;
        pthread_t _thread;
        method_ptr_t _func;
        void *_args;
        bool _created;
    };
}

#endif /* !THREAD_HPP_ */
