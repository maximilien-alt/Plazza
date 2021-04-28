/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-lucas.dudot
** File description:
** PizzaFactory
*/

#pragma once

#include "Error.hpp"
#include "APizza.hpp"
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"

namespace Plazza {
    class PizzaFactory {
        public:
            PizzaFactory() {
                _map["margarita"] = [](PizzaSize size, int orderId, int pizzaId, float time) {return std::make_shared<Plazza::Margarita>(size, orderId, pizzaId, time);};
                _map["regina"] = [](PizzaSize size, int orderId, int pizzaId, float time) {return std::make_shared<Plazza::Regina>(size, orderId, pizzaId, time);};
                _map["americana"] = [](PizzaSize size, int orderId, int pizzaId, float time) {return std::make_shared<Plazza::Americana>(size, orderId, pizzaId, time);};
                _map["fantasia"] = [](PizzaSize size, int orderId, int pizzaId, float time) {return std::make_shared<Plazza::Fantasia>(size, orderId, pizzaId, time);};
            };
            ~PizzaFactory() = default;

            std::shared_ptr<APizza> giveMeAPizza(std::string field, PizzaSize size, int orderId, int pizzaId, float time) {
                if (_map.find(field) == _map.end())
                    throw Error("[Factory, GiveMeAPizza]: The pizza '" + field + "' does not exist!");
                return (_map[field](size, orderId, pizzaId, time));
            };

        private:
            std::unordered_map<std::string, std::function<std::shared_ptr<APizza>(PizzaSize, int, int, float)>> _map;
    };
}

