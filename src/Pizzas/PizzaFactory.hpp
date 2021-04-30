/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-lucas.dudot
** File description:
** PizzaFactory
*/

#pragma once

#include "../Error.hpp"
#include "APizza.hpp"
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"

namespace Plazza
{
    class PizzaFactory
    {
    public:
        PizzaFactory()
        {
            _map["margarita"] = [](PizzaSize size, int orderId, int pizzaId, float time) { return std::make_shared<Plazza::Margarita>(size, orderId, pizzaId, time); };
            _map["regina"] = [](PizzaSize size, int orderId, int pizzaId, float time) { return std::make_shared<Plazza::Regina>(size, orderId, pizzaId, time); };
            _map["americana"] = [](PizzaSize size, int orderId, int pizzaId, float time) { return std::make_shared<Plazza::Americana>(size, orderId, pizzaId, time); };
            _map["fantasia"] = [](PizzaSize size, int orderId, int pizzaId, float time) { return std::make_shared<Plazza::Fantasia>(size, orderId, pizzaId, time); };
        };
        ~PizzaFactory() = default;

        static std::string pack(APizza &pizza)
        {
            Plazza::PizzaSize size(pizza.getSize());
            std::string strSize;
            strSize << size;
            Plazza::PizzaType type(pizza.getType());
            std::string strType;
            strType << type;
            return std::string(strType + " " + strSize + " " + std::to_string(pizza.getOrderId()) + " " + std::to_string(pizza.getPizzaId()));
        }

        static Plazza::APizza unpack(std::string str, float time)
        {
            std::vector<std::string> vector;
            size_t pos = 0;
            std::string token;

            while ((pos = str.find(' ')) != std::string::npos)
            {
                token = str.substr(0, pos);
                vector.push_back(token);
                str.erase(0, pos + 1);
            }
            if (!str.empty())
                vector.push_back(str);

            Plazza::PizzaSize size;
            size << vector[1];
            if (vector[0] == "margarita")
                return Plazza::Margarita(size, std::stoi(vector[2]), std::stoi(vector[3]), time);
            if (vector[0] == "regina")
                return Plazza::Regina(size, std::stoi(vector[2]), std::stoi(vector[3]), time);
            if (vector[0] == "americana")
                return Plazza::Americana(size, std::stoi(vector[2]), std::stoi(vector[3]), time);
            if (vector[0] == "fantasia")
                return Plazza::Fantasia(size, std::stoi(vector[2]), std::stoi(vector[3]), time);
        }

        std::shared_ptr<APizza> giveMeAPizza(std::string field, PizzaSize size, int orderId, int pizzaId, float time)
        {
            if (_map.find(field) == _map.end())
                throw Error("[Factory, GiveMeAPizza]: The pizza '" + field + "' does not exist!");
            //APizza
            return (_map[field](size, orderId, pizzaId, time));
        };

    private:
        std::unordered_map<std::string, std::function<std::shared_ptr<APizza>(PizzaSize, int, int, float)>> _map;
    };
}
