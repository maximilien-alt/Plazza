/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "../Order.hpp"

namespace Plazza {
    class Reception {
        public:
            Reception(const float time);
            ~Reception();

            std::vector<Order> getOrders(bool &);

        private:
            std::string _line;
            float _timeMultiplier;
            int _ids;
            std::vector<std::string> _currentOrders;

            void displayStatus();
            void OneOrder(Plazza::Order &);
    };
}

#endif /* !RECEPTION_HPP_ */