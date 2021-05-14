/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Socket
*/

#include "Socket.hpp"

Plazza::Socket::Socket()
{
    newSocket();
}

Plazza::Socket::~Socket()
{
    close(_socketId);
}

void Plazza::Socket::createServerSocket()
{
    unlink("socket");
    if (bind(_socketId, (struct sockaddr *)&_settings, sizeof(_settings)) == -1)
        throw Error("[Create Socket Server]: Fail binding socket!");
    if (listen(_socketId, 1) == -1)
        throw Error("[Create Socket Server]: Fail listening socket!");
    FD_SET(_socketId, &_activeFds);
}

int Plazza::Socket::_select()
{
    _readFds = _activeFds;
    return (select(FD_SETSIZE, &_readFds, NULL, NULL, NULL));
}

int Plazza::Socket::_accept()
{
    return (accept(_socketId, NULL, NULL));
}

void Plazza::Socket::_connect()
{
    while (connect(_socketId, (const struct sockaddr *) &_settings, sizeof(_settings)) == -1);
}

fd_set &Plazza::Socket::getActiveFds()
{
    return (_activeFds);
}

void Plazza::Socket::setActiveFd(int fd)
{
    FD_SET(fd, &_activeFds);
}

int Plazza::Socket::getFdsSize()
{
    return (FD_SETSIZE);
}

bool Plazza::Socket::isFdSet(int fd)
{
    return (FD_ISSET(fd, &_readFds));
}

void Plazza::Socket::newSocket()
{
    _socketId = socket(AF_UNIX, SOCK_STREAM, 0);
    memset(&_settings, 0, sizeof(_settings));
    _settings.sun_family = AF_UNIX;
    strncpy(_settings.sun_path, "socket", sizeof(_settings.sun_path) - 1);
    FD_ZERO(&_activeFds);
}

int Plazza::Socket::getSocketId() const
{
    return _socketId;
}

FILE *Plazza::Socket::_fdopen(int fd, std::string mode)
{
    return (fdopen(fd, mode.c_str()));
}

std::string Plazza::Socket::_getline(FILE *fp)
{
    size_t size = 0;
    char *buffer = NULL;

    if (getline(&buffer, &size, fp) == -1)
        throw Error("[GetLine]: Failed!");
    std::string result(buffer);
    free (buffer);
    result.erase(--result.end());
    return result;
}

void Plazza::Socket::clearFd(int fd)
{
    FD_CLR(fd, &_activeFds);
}