/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_

#include "../include/include.hpp"
#include "Pizza.hpp"

namespace Plazza {
    class Order {
        public:
            Order(const std::string &);
            ~Order();

            size_t getSize() const;
            std::vector<Pizza> &getPizzas();

        private:
            std::vector<Pizza> _pizzas;
            size_t _size;
    };
}

#endif /* !ORDER_HPP_ */