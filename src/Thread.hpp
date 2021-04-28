/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "../include/include.hpp"

namespace Plazza
{
    class Thread
    {
    public:
        enum STATUS
        {
            RUNNING,
            DEAD
        };

        template <class Fn, class... Args>
        explicit Thread (Fn&& fn, Args&&... args): _thread(fn, args...), _status(RUNNING), _created(1) {
        };

        ~Thread();

        void joinThreads();

        void cancel();

        STATUS getCurrentStatus() const;

    private:
        std::thread _thread;
        STATUS _status;
        bool _created;
    };
}

#endif /* !THREAD_HPP_ */
