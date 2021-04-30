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
            void addKitchen(int, Kitchen &);
            Kitchen giveMeKitchen(int, int, int);
            void dump();
            size_t size() const;
            Kitchen &at(int pos);

        private:
            std::unordered_map<int, Kitchen> _kitchens;
    };
}

#endif /* !KITCHENMANAGER_HPP_ */