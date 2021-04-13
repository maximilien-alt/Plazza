/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#include "Thread.hpp"

Plazza::Thread::Thread(method_ptr_t start, void *args): _status(STARTED), _func(start), _args(args), _created(0)
{

}

Plazza::Thread::~Thread()
{
    if (_status != DEAD && _created)
        pthread_join(_thread, nullptr);
};

void Plazza::Thread::run()
{
    if (_status == RUNNING)
        return;
    _status = RUNNING;
    if (pthread_create(&_thread, NULL, _func, _args) != 0)
        _status = DEAD;
    else
        _created = 1;
};

void Plazza::Thread::cancel()
{
    if (_status == DEAD)
        return;
    _status = DEAD;
    pthread_cancel(_thread);
}

Plazza::Thread::STATUS Plazza::Thread::getCurrentStatus() const
{
    return (_status);
}