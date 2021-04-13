/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** AMutex
*/

#ifndef AMUTEX_HPP_
#define AMUTEX_HPP_

#include "IMutex.hpp"
#include "../include/include.hpp"

namespace Plazza {

    class AMutex : public IMutex
    {
        public:
            AMutex();
            void lock() final;
            void unlock() final;
            void trylock() final;

        private:
            pthread_mutex_t mutex_stock;
    };
}

#endif /* !AMUTEX_HPP_ */
