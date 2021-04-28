/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include "../include/include.hpp"
#include "Error.hpp"

namespace Plazza {
    class Socket {
        public:
            Socket();
            ~Socket();

            int _select();
            int _accept();
            void _connect(int);
            void newSocket();

            int getFdsSize();
            fd_set &getActiveFds();
            int getSocketId() const;
            std::string _getline(FILE *);
            int getListenginPort() const;

            bool isFdSet(int fd);
            FILE *_fdopen(int fd, std::string mode);
            void setActiveFd(int fd);

            void createServerSocket();

        private:
            int _socketId;
            int _listeningPort;
            struct sockaddr_in _settings;
            fd_set _activeFds;
            fd_set _readFds;
    };
}

#endif /* !SOCKET_HPP_ */