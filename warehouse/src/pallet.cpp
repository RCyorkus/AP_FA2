#include "include/pallet.hpp"

#include <iostream>

Pallet::Pallet(){
    this->itemName = "emptyItem";
    this->itemCapacity = 0;
    this->itemCount = 0;
}

Pallet::Pallet(std::string itemName, int itemCapacity,int itemCount): itemName(itemName), itemCapacity(itemCapacity),itemCount(itemCount){}

std::string Pallet::getItemName(){
    return itemName;
}

int Pallet::getItemCount(){
    return itemCount;
}

int Pallet::getRemainingSpace(){
    return itemCapacity - itemCount;
}

/**
 * Reallocates an empty pallet with the specified item name and item capacity.
 * 
 * @param itemName The name of the item for the pallet.
 * @param itemCapacity The capacity of the item for the pallet.
 * @return True indicating the successful reallocation of the empty pallet.
 */
bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    this->itemName = itemName;
    this->itemCount = 0;
    this->itemCapacity = itemCapacity;
    return true;
}

bool Pallet::takeOne(){
    if(itemCount >= 1){
        itemCount --;
        return true;
    }
    else{
        return false;
    }
}

bool Pallet::putOne(){
    if(getRemainingSpace() > 0){
        itemCount ++;
        return true;
    }
    else{
        return false;
    }
}