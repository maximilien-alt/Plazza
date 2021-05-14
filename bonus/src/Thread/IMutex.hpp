/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
#define IMUTEX_HPP_

#include "../../include/include.hpp"


namespace Plazza {
    class IMutex
    {
        public:
            virtual ~IMutex() = default;
            virtual void lock() = 0;
            virtual void unlock() = 0;
            virtual void trylock() = 0;
    };
}

#endif /* !IMUTEX_HPP_ */