/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "AMutex.hpp"
#include "../include/include.hpp"

namespace Plazza {
    class ScopedLock {
        public:
            ScopedLock(std::shared_ptr<IMutex> &mutex);
            ~ScopedLock();

        private:
            std::shared_ptr<IMutex> &_mutex;
    };
}

#endif /* !SCOPEDLOCK_HPP_ */