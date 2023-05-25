#include <iostream>
#include <array>

#include "src/include/warehouse.hpp"
#include "src/include/employee.hpp"
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"


int main(void){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);
    
    warehouse.addEmployee(Employee("Bob", true));

    std::cout << "de orginale shelf" << std::endl;
    warehouse.shelves[0].printShelfItems();

    warehouse.rearrangeShelf(warehouse.shelves[0]);

    std::cout << "gesorteerd" << std::endl;
    warehouse.shelves[0].printShelfItems();

    warehouse.pickItems("Toy Bears", 21);
    
    std::cout << "er zijn 21 beren gepakt" << std::endl;
    warehouse.shelves[2].printShelfItems();
}
