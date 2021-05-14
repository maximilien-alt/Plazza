/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** AMutex
*/

#include "AMutex.hpp"

Plazza::AMutex::AMutex()
{
    mutex_stock = PTHREAD_MUTEX_INITIALIZER;
};

void Plazza::AMutex::lock()
{
    pthread_mutex_lock(&mutex_stock);
};

void Plazza::AMutex::unlock()
{
    pthread_mutex_unlock(&mutex_stock);
};

void Plazza::AMutex::trylock()
{
    pthread_mutex_trylock(&mutex_stock);
};