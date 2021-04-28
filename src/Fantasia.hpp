/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Fantasia
*/

#ifndef Fantasia_HPP_
#define Fantasia_HPP_

#include "APizza.hpp"

namespace Plazza {
    class Fantasia: public APizza {
        public:
            Fantasia(const PizzaSize &size, const int &orderId, const int &pizzaId, const float timeMultiplier): APizza(size, orderId, pizzaId, timeMultiplier * 4, Ingredients::Doe, Ingredients::Tomato, Ingredients::EggPlant, Ingredients::Goat_Cheese, Ingredients::Chief_Love) {};
            ~Fantasia() = default;
    };
}

#endif /* !Fantasia_HPP_ */