/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Regina
*/

#ifndef Regina_HPP_
#define Regina_HPP_

#include "APizza.hpp"

namespace Plazza {
    class Regina: public APizza {
        public:
            Regina(const PizzaSize &size, const int &orderId, const int &pizzaId, const float timeMultiplier): APizza(size, orderId, pizzaId, timeMultiplier * 2, Ingredients::Doe, Ingredients::Tomato, Ingredients::Gruyere, Ingredients::Ham, Ingredients::Mushrooms) {};
            ~Regina() = default;
    };
}

#endif /* !Regina_HPP_ */