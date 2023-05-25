#pragma once

#include <iostream>

class Pallet{
    private:
        std::string itemName;
        int itemCapacity;
        int itemCount;
        
    
    public:
        Pallet();

        Pallet(std::string itemName,int itemCapacity, int intemCount);

        std::string getItemName();

        int getItemCount();

        int getRemainingSpace();

        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

        bool takeOne();

        bool putOne();
};