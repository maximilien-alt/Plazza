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
#include "KitchenManager.hpp"

namespace Plazza {
    class Reception {
        public:
            Reception();
            ~Reception();

            std::vector<Order> getOrders(bool &);

        private:
            std::string _line;
            std::vector<std::string> _currentOrders;

            void displayStatus();
            void OneOrder(Plazza::Order &);
    };
}

#endif /* !RECEPTION_HPP_ */