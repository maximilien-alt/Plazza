/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

Plazza::ScopedLock::ScopedLock(std::shared_ptr<IMutex> &mutex) : _mutex(mutex)
{
    _mutex.get()->lock();
}
Plazza::ScopedLock::~ScopedLock()
{
    _mutex.get()->unlock();
}