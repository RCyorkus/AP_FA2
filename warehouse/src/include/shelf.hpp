#pragma once

#include <iostream>
#include <array>
#include "pallet.hpp"

class Shelf{
    public:
        std::array<Pallet, 4> pallets;

    Shelf();

    bool swapPallet(const int slot,const int slot2);

    std::string shelfItem(const int slot);
};