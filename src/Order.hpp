/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_

#include "Error.hpp"
#include "Pizzas/PizzaFactory.hpp"

namespace Plazza {
    class Order {
        public:
            Order(const std::string &, int, float);
            ~Order();

            size_t getSize() const;
            std::unordered_map<int, std::shared_ptr<Plazza::APizza>> &getPizzas();
            int getOrderId() const;

        private:
            PizzaFactory _factory;
            std::unordered_map<int, std::shared_ptr<APizza>> _pizzas;
            size_t _size;
            int _id;
            float _time;
    };
}

#endif /* !ORDER_HPP_ */