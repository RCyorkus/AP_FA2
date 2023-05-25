#include "include/warehouse.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"

#include <iostream>
#include <vector>


Warehouse::Warehouse(){}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

/**
 * loop trough shelf and swap items to order based on item count.
 * you have to keep looping trough till there has not been any sortings,
 * so you know its al sorted
 * 
 * @param shelf The shelf to be sorted.
 * @return True if any pallets were swapped, otherwise false.
 */
bool shelfLoop(Shelf& shelf){
    bool sorting = false;

    for(int i =0; i <= 3; i++){ // for the shelf length - 1
        if(shelf.pallets[i].getItemCount() > shelf.pallets[i + 1].getItemCount()){ // check if the first item is bigger the the second
            shelf.swapPallet(i, i+1); // switch items
            sorting = true;
        }
    }

    return sorting;
}

/**
 * Rearranges the pallets on a shelf based on item count.
 * Only employees with a forklift certificate can perform this operation.
 * 
 * @param shelf The shelf to be rearranged.
 * @return True if the shelf is successfully rearranged, otherwise false.
 */
bool Warehouse::rearrangeShelf(Shelf& shelf){
    if(Employees[0].forkliftCertificate == false || Employees[0].busy == true ){
        return false;
    }

    bool sorting = true;
    while (sorting) // while the shelf isn't sorted
    {
        sorting = shelfLoop(shelf);
    }
    return true;
}


/**
 * Checks if there are enough items of a specified item in all shelves.
 * 
 * @param shelves The vector of shelves.
 * @param itemName The name of the item.
 * @param itemCount The required number of items.
 */
bool enoughItems(std::vector<Shelf>& shelves, const std::string& itemName, int& itemCount){
    int totalItemCount = 0; // count to keep track of total number of items in all shelfs

    for (Shelf Shelf : shelves){ // loop trough all shelves
        for (Pallet pallet : Shelf.pallets) { // loop trough
            if (pallet.getItemName() == itemName) { // check voor item
                totalItemCount += pallet.getItemCount();
                if(totalItemCount >= itemCount){
                    return true;
                }
            }
        }
    }
    return false; 
}

/**
 * Picks the specified number of items in all shelves.
 * 
 * @param shelves The vector of shelves.
 * @param itemName The name of the item.
 * @param itemCount The number of items to be picked (updated with the remaining count).
 */
void pick(std::vector<Shelf>& shelves, const std::string& itemName, int& itemCount){
    for (Shelf& Shelf : shelves){
        for (Pallet& pallet : Shelf.pallets) { // voor pallets
            if (pallet.getItemName() == itemName) { // check voor item
                while (itemCount > 0 && pallet.getItemCount() > 0) {
                    pallet.takeOne(); // pak item van pallet
                    itemCount--; // update count
                }
            }
        }
    }
}

/**
 * Picks the specified number of items of the given item from the shelves.
 * 
 * @param itemName The name of the item.
 * @param itemCount The number of items to be picked.
 * @return True if all items are picked, otherwise false.
 */
bool Warehouse::pickItems(const std::string& itemName, int itemCount){
    if (enoughItems(shelves, itemName, itemCount)) { 
        pick(shelves, itemName, itemCount);
    }

    return(itemCount == 0); // deze manier van returnen was een tip van GPT
}
