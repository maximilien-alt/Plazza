/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Fridge
*/

#ifndef FRIDGE_HPP_
#define FRIDGE_HPP_

#include "../../include/include.hpp"
#include "../Pizzas/APizza.hpp"

namespace Plazza {
    class Fridge {
        public:
            Fridge();
            ~Fridge();

            std::unordered_map<Ingredients, int> &getContent();
            bool canCook(APizza pizza);
            void refillStock();
            void selectIngredients(APizza pizza);
            void showContent() const;

            static std::string packIngredient(Ingredients);

        private:
            std::unordered_map<Ingredients, int> _content;
    };
}

#endif /* !FRIDGE_HPP_ */