/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Clock
*/

#ifndef GAMECLOCK_HPP_
#define GAMECLOCK_HPP_

#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock _Clock;

namespace Plazza
{
    class Clock
    {
        public:
            Clock();
            ~Clock();
            void reset();
            float getElapsedTime();

        private:
            std::chrono::_V2::system_clock::time_point _clock = _Clock::now();

    };
}

#endif /* !GAMECLOCK_HPP_ */