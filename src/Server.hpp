/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "../include/include.hpp"
#include "KitchenManager.hpp"
#include "Socket.hpp"
#include "Reception.hpp"

namespace Plazza {
    class Server {
        public:
            Server(const int &, const int &, const int &);
            ~Server();

            void loop();

        private:
            int _timeMultiplier;
            int _cooksPerKitchen;
            int _ingredientsCoolDown;
            Socket _socket;
            Reception *_reception;
            KitchenManager _kitchenManager;
            void acceptOrRead(int);
            void createKitchen();
            void parseOrders(std::vector<Plazza::Order> orders);
            std::string readFromKitchen(int fd);
            void OneOrder(Plazza::Order order);
            std::unordered_map<int, Order> _storage;
    };
}

#endif /* !SERVER_HPP_ */