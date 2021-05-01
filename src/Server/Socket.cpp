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
    if (bind(_socketId, (struct sockaddr *)&_settings, sizeof(_settings)) == -1)
        throw Error("[Create Socket Server]: Fail binding socket!");
    socklen_t len = sizeof(_settings);
    if (getsockname(_socketId, (struct sockaddr *)&_settings, &len) == -1)
        throw Error("[Create Socket Server]: Fail getsockname socket!");
    if (listen(_socketId, 1) == -1)
        throw Error("[Create Socket Server]: Fail listening socket!");
    _listeningPort = ntohs(_settings.sin_port);
    FD_SET(_socketId, &_activeFds);
}

int Plazza::Socket::_select()
{
    _readFds = _activeFds;
    return (select(FD_SETSIZE, &_readFds, NULL, NULL, &t));
}

int Plazza::Socket::_accept()
{
    int size = sizeof(_settings);

    return (accept(_socketId, (struct sockaddr *)&_settings, (socklen_t *)&size));
}

void Plazza::Socket::_connect(int listeningPort)
{
    _settings.sin_port = ntohs(listeningPort);
    while (connect(_socketId, (struct sockaddr *)&_settings, sizeof(_settings)) == -1);
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
    _socketId = socket(PF_INET, SOCK_STREAM, 0);
    bzero((char *) &_settings, sizeof(_settings));
    _settings.sin_family = AF_INET;
    _settings.sin_port = 0;
    _settings.sin_addr.s_addr = inet_addr("127.0.0.1");
    FD_ZERO(&_activeFds);
    t.tv_sec = 1;
    t.tv_usec = 0;
}

int Plazza::Socket::getSocketId() const
{
    return _socketId;
}

int Plazza::Socket::getListenginPort() const
{
    return (_listeningPort);
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