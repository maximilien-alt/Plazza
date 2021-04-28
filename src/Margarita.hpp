/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "APizza.hpp"

namespace Plazza {
    class Margarita: public APizza {
        public:
            Margarita(const PizzaSize &size, const int &orderId, const int &pizzaId, const float timeMultiplier): APizza(size, orderId, pizzaId, timeMultiplier, Ingredients::Doe, Ingredients::Tomato, Ingredients::Gruyere) {};
            ~Margarita() = default;
    };
}

#endif /* !MARGARITA_HPP_ */