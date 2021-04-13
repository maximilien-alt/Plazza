/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#include "Thread.hpp"

Plazza::Thread::~Thread()
{
    if (_status != DEAD && _created)
        _thread.join();
};

void Plazza::Thread::cancel()
{
    if (_status == DEAD)
        return;
    _status = DEAD;
    _thread.detach();
}

Plazza::Thread::STATUS Plazza::Thread::getCurrentStatus() const
{
    return (_status);
}