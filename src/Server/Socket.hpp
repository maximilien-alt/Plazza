/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include "../../include/include.hpp"
#include "../Error.hpp"

namespace Plazza {
    class Socket {
        public:
            Socket();
            ~Socket();

            int _select();
            int _accept();
            void _connect();
            void newSocket();

            int getFdsSize();
            fd_set &getActiveFds();
            int getSocketId() const;
            std::string _getline(FILE *);

            bool isFdSet(int fd);
            FILE *_fdopen(int fd, std::string mode);
            void setActiveFd(int fd);
            void clearFd(int);

            void createServerSocket();

        private:
            int _socketId;
            struct timeval t;
            struct sockaddr_un _settings;
            fd_set _activeFds;
            fd_set _readFds;
    };
}

#endif /* !SOCKET_HPP_ */