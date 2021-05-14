/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "../../include/include.hpp"
#include "../Kitchens/KitchenManager.hpp"
#include "Socket.hpp"
#include "Reception.hpp"

namespace Plazza {
    class Server {
        public:
            Server(const int &, const int &, const int &, int);
            ~Server();

            void loop();

        private:
            int _timeMultiplier;
            int _cooksPerKitchen;
            int _ingredientsCoolDown;
            int _ordersfd;
            Socket _socket;
            Reception *_reception;
            std::unordered_map<int, Order> _storage;
            KitchenManager _kitchenManager;
            std::ofstream log;

            void acceptOrRead(int);
            void createKitchen();
            void parseOrders(std::vector<Plazza::Order> orders);
            void readFromKitchen(int fd);
            void OneOrder(Plazza::Order order);
            void updateCookedPizzaStatus(int, int);
            void writeOrderToLog(Plazza::Order order);
    };
}

#endif /* !SERVER_HPP_ */