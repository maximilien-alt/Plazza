/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Error
*/

#pragma once

#include <exception>
#include <iostream>

namespace Plazza {
    class Error: public std::exception
    {
        public:
            Error(std::string const &message,
                    std::string const &component = "Unknown") noexcept;

            std::string const &getComponent() const;
            const char *what() const noexcept final;

        private:
            std::string _message;
            std::string _component;
    };
}