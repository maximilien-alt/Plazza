/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../include/include.hpp"

namespace Plazza {
    class Cook {
        public:
            Cook();
            ~Cook() = default;

            bool isCooking() const;

        private:
            bool _isCooking;
    };
}

#endif /* !COOK_HPP_ */