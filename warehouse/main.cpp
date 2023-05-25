#include <iostream>
#include <array>

#include "src/include/warehouse.hpp"
#include "src/include/employee.hpp"
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"

int main(void){
    std::cout << "Hello world" << std::endl;
    Employee e1("ruben", true);

    Shelf s1 = Shelf();

    std::array<Pallet, 4> pallets = {Pallet("auto",100,4), Pallet("fiets",100,1), Pallet("steen",100,5), Pallet("ballen",100,2)};
    s1.pallets = pallets;

    Warehouse house = Warehouse();
    house.addEmployee(e1);

    house.rearrangeShelf(s1);


    std::cout << s1.shelfItem(0) << std::endl;
    std::cout << s1.shelfItem(1) << std::endl;
    std::cout << s1.shelfItem(2) << std::endl;
    std::cout << s1.shelfItem(3) << std::endl;

    // house.addShelf(s1);
    // std::cout << "here" << std::endl;
    // std::cout << house.pickItems("auto", 3) << std::endl;
    // s1.swapPallet(0,1);

    // std::cout << s1.shelfItem(0) << std::endl;
    // std::cout << s1.shelfItem(1) << std::endl;

    // std::cout << p1.getItemName() << std::endl;
}
