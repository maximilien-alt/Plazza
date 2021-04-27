/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "../include/include.hpp"
#include "Error.hpp"

namespace Plazza
{
    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8,
        None = 16
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16,
        Null = 32
    };

    class Pizza
    {
        public:
            Pizza(const std::string &, const std::string &);
            ~Pizza();

            PizzaType getType() const;
            PizzaSize getSize() const;

        private:
            PizzaType _type;
            PizzaSize _size;
    };
}

std::ostream &operator<<(std::ostream &s, const Plazza::Pizza &rhs);

#endif /* !PIZZA_HPP_ */