/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include "../include/include.hpp"

namespace Plazza
{
    enum Ingredients
    {
        Doe,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        EggPlant,
        Goat_Cheese,
        Chief_Love,
        Nothing
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

    class APizza {
        public:
            APizza(const PizzaSize &, const int &, const int &, const float &, const Ingredients &, const Ingredients &, const Ingredients &, const Ingredients & = Nothing, const Ingredients & = Nothing);
            ~APizza();

            std::vector<Ingredients> getIngredients() const;
            int getOrderId() const;
            int getPizzaId() const;
            float getBakedTime() const;
            bool isCooked() const;
            PizzaSize getSize() const;

            void setCookingStatus(bool);

        protected:
            PizzaSize _size;
            std::vector<Ingredients> _ingredients;
            int _orderId;
            int _pizzaId;
            float _bakedTime;
            bool _isCooked = false;
    };
}

Plazza::PizzaSize& operator<<(Plazza::PizzaSize &lhs, const std::string &rhs);
std::string& operator<<(std::string &lhs, Plazza::PizzaSize &rhs);

#endif /* !APIZZA_HPP_ */