/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include "../../include/include.hpp"

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

    enum PizzaType
    {
        margarita,
        regina,
        americana,
        fantasia
    };

    class APizza {
        public:
            APizza() = default;
            APizza(const PizzaSize &, const int &, const int &, const float &, const Ingredients &, const Ingredients &, const Ingredients &, const Ingredients & = Nothing, const Ingredients & = Nothing);
            virtual ~APizza();

            std::vector<Ingredients> getIngredients() const;
            int getOrderId() const;
            int getPizzaId() const;
            float getBakedTime() const;
            bool isCooked() const;
            PizzaSize getSize() const;
            PizzaType getType() const;

            void setCookingStatus(bool);
            void setIngredients(std::vector<Ingredients>);
            void setOrderId(int);
            void setPizzaId(int);
            void setBakedTime(float);
            void setSize(PizzaSize);
            void setType(PizzaType);

        protected:
            PizzaSize _size;
            std::vector<Ingredients> _ingredients;
            int _orderId;
            int _pizzaId;
            float _bakedTime;
            bool _isCooked = false;
            PizzaType _type;
    };
}

Plazza::PizzaSize& operator<<(Plazza::PizzaSize &lhs, const std::string &rhs);
std::string& operator<<(std::string &lhs, Plazza::PizzaSize &rhs);
Plazza::PizzaType& operator<<(Plazza::PizzaType &lhs, const std::string &rhs);
std::string& operator<<(std::string &lhs, Plazza::PizzaType &rhs);
std::ostream &operator<<(std::ostream &s, const Plazza::APizza &rhs);

#endif /* !APIZZA_HPP_ */