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
#include "Reception.hpp"

namespace Plazza {
    class Server {
        public:
            Server(const int &, const int &, const int &);
            ~Server();

            int initSocket();
            void loop();

        private:
            int _timeMultiplier;
            int _cooksPerKitchen;
            int _ingredientsCoolDown;
            int _socketId;
            int _listeningPort;
            struct sockaddr_in _settings;
            fd_set _activeFds;
            fd_set _readFds;
            Reception *_reception;
            KitchenManager _kitchenManager;
            void acceptOrRead(int);
            void createKitchen();
            void parseOrders(std::vector<Plazza::Order> orders);
            void readFromKitchen(int fd);
            void OneOrder(Plazza::Order &order);
    };
}

#endif /* !SERVER_HPP_ */