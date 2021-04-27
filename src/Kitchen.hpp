/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "../include/include.hpp"
#include "Cook.hpp"
#include "Order.hpp"

namespace Plazza {
    class Kitchen {
        public:
            Kitchen(const int &, const int &, const int &);
            ~Kitchen();

            void dump() const;
            int howManyPizzasCanITake() const;
            int howManyPizzasAreCooking() const;
            void addPizzaToQueue(Plazza::Pizza &);
            void takeOrder(Plazza::Order &);

        private:
            int _cooksNumber;
            int _IngredientsCoolDown;
            int _timeMultiplier;
            std::vector<Plazza::Cook> _cooks;
            ISafeQueue *_queue;
    };
}

#endif /* !KITCHEN_HPP_ */