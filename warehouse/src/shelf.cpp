#include "include/shelf.hpp"
#include "include/pallet.hpp"

#include <iostream>
#include <array>

Shelf::Shelf(){
    this->pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
}

/**
 * switch 2 items on given slots.
 * 
 * @param slot index of the first item.
 * @param slot2 index of the second item.
 * @return True if items has been switched, otherwise false.
*/
bool Shelf::swapPallet(const int slot, const int slot2){
    if(slot <= 4 && slot2 <= 4){
        Pallet temp = pallets[slot];
        pallets[slot] = pallets[slot2];
        pallets[slot2] = temp;

        return true;
    }
    else{
        return false;
    }
}

std::string Shelf::shelfItem(const int slot){
    return pallets[slot].getItemName();
}