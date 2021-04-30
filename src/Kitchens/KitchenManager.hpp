/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** KitchenManager
*/

#ifndef KITCHENMANAGER_HPP_
#define KITCHENMANAGER_HPP_

#include "../../include/include.hpp"
#include "Kitchen.hpp"

namespace Plazza {
    class KitchenManager {
        public:
            KitchenManager();
            ~KitchenManager();

            bool empty() const;
            void addKitchen(int fd, Kitchen &kitchen, int maxPizzas);
            Kitchen giveMeKitchen(int, int, int);
            void dump();
            size_t size() const;
            std::pair<const std::shared_ptr<Plazza::Kitchen>, int> &at(int pos);
            void deleteKitchenFromFd(int fd);
            void updateMaxPizzasFromFd(int fd, int state);

        private:
            std::unordered_map<std::shared_ptr<Kitchen>, int> _kitchens;
    };
}

#endif /* !KITCHENMANAGER_HPP_ */