/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Americana
*/

#ifndef Americana_HPP_
#define Americana_HPP_

#include "APizza.hpp"

namespace Plazza {
    class Americana: public APizza {
        public:
            Americana(const PizzaSize &size, const int &orderId, const int &pizzaId, const float timeMultiplier): APizza(size, orderId, pizzaId, timeMultiplier * 2, Ingredients::Doe, Ingredients::Tomato, Ingredients::Gruyere, Ingredients::Steak)
            {
                _type = Plazza::PizzaType::americana;
            };
            ~Americana() = default;
    };
}

#endif /* !Americana_HPP_ */