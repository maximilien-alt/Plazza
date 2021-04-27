/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "Order.hpp"
#include "Kitchen.hpp"

namespace Plazza {
    class Reception {
        public:
            Reception(const int &, const int &, const int &);
            ~Reception();

            void loopOrders();
            void HandleOrders();
            void OneOrder(Plazza::Order &);

        private:
            int _timeMultiplier;
            int _cooksPerKitchen;
            int _IngredientsCoolDown;
            std::string _line;
            std::vector<std::string> _currentOrders;
            std::vector<Plazza::Order> _orders;
            std::vector<Kitchen> _kitchens;

            void displayStatus();
    };
}

#endif /* !RECEPTION_HPP_ */