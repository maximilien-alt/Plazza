/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../include/include.hpp"
#include "Pizza.hpp"
#include "AMutex.hpp"

namespace Plazza {
    class Cook {
        public:
            Cook();
            ~Cook();

            bool isCooking() const;
            void cook(Pizza toCook);

        private:
            bool _isCooking;
    };
}

#endif /* !COOK_HPP_ */