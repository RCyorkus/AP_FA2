#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"

bool operator==( Pallet lhs,  Pallet rhs){
    return (lhs.getItemName() == rhs.getItemName());
}


// ...::: pallet :::...
TEST_CASE("The pallet constructor actually assigns the provided values to the attributes", "pallet constructor"){
    Pallet p1 = Pallet("auto", 100, 4);

    REQUIRE(p1.getItemName() == "auto");
    REQUIRE(p1.getRemainingSpace() == 96);
    REQUIRE(p1.getItemCount() == 4);
}
TEST_CASE("check if all functions for the pallet work", "pallet functions"){
    Pallet p1 = Pallet("auto", 100, 4);

    p1.takeOne(); 
    REQUIRE(p1.getItemCount() == 3);

    p1.putOne(); 
    REQUIRE(p1.getItemCount() == 4);

    Pallet p2 = Pallet();
    p2.reallocateEmptyPallet("fiets", 10);  
    REQUIRE(p2.getItemName() == "fiets");
    REQUIRE(p2.getRemainingSpace() == 10);

}

// ...::: shelf :::...
TEST_CASE("The shelf constructor actually assigns the provided values to the attributes", "shelf constructor"){
    Shelf s1 = Shelf();
    std::array<Pallet, 4> pallets = {Pallet("auto",100,4), Pallet(), Pallet(), Pallet()};
    s1.pallets = pallets;

    REQUIRE(s1.pallets[0]  == Pallet("auto",100,4));
    REQUIRE(s1.pallets[1]  == Pallet());
    REQUIRE(s1.pallets[2]  == Pallet());
    REQUIRE(s1.pallets[3]  == Pallet());
}

TEST_CASE("check if all functions for the shelf work", "shelf functions"){
    Shelf s1 = Shelf();

    std::array<Pallet, 4> pallets = {Pallet("auto",100,4), Pallet("fiets",100,1), Pallet("steen",100,5), Pallet("ballen",100,2)};
    s1.pallets = pallets;

    s1.swapPallet(0,1);

    REQUIRE(s1.pallets[0] == Pallet("fiets",100,1));
    REQUIRE(s1.pallets[1] == Pallet("auto",100,4));
}

// ...::: employee :::...
TEST_CASE("The employee constructor actually assigns the provided values to the attributes", "employee constructor"){
    Employee e1 = Employee("ruben", true);
    
    REQUIRE(e1.getName() == "ruben");
    REQUIRE(e1.forkliftCertificate == true);
    REQUIRE(e1.busy == false);
}



// ...::: warehouse :::...
TEST_CASE("The warehouse constructor actually assigns the provided values to the attributes", "warehouse constructor"){
    Shelf s1 = Shelf();
    Employee e1 = Employee("ruben", true);

    std::array<Pallet, 4> pallets = {Pallet("auto",100,4), Pallet("fiets",100,1), Pallet("steen",100,5), Pallet("ballen",100,2)};
    s1.pallets = pallets;

    Warehouse house = Warehouse();

    house.addShelf(s1);
    house.addEmployee(e1);

    REQUIRE(house.Employees[0].getName() == "ruben");
    REQUIRE(house.shelves[0].pallets[0] == Pallet("auto",100,4));
}

TEST_CASE("rearrangeshelf orders the shelf on item count from low to high", "warehouse function"){
    Employee e1("ruben", true);
    Shelf s1 = Shelf();

    std::array<Pallet, 4> pallets = {Pallet("auto",100,4), Pallet("fiets",100,1), Pallet("steen",100,5), Pallet("ballen",100,2)};
    s1.pallets = pallets;

    Warehouse house = Warehouse();
    house.addEmployee(e1);

    house.rearrangeShelf(s1);

    REQUIRE(s1.shelfItem(0) == "fiets");
    REQUIRE(s1.shelfItem(1) == "ballen");
    REQUIRE(s1.shelfItem(2) == "auto");
    REQUIRE(s1.shelfItem(3) == "steen");
}

TEST_CASE("pickitems pick items from pallet by name and amount", "warehouse function"){
    Shelf s1 = Shelf();
    std::array<Pallet, 4> pallets = {Pallet("auto",10,4), Pallet("fiets",10,1), Pallet("steen",10,5), Pallet("steen",10,2)};
    s1.pallets = pallets;

    Warehouse house = Warehouse();
    house.addShelf(s1);


    REQUIRE(house.pickItems("auto", 3) == true);
    REQUIRE(house.shelves[0].pallets[0].getItemCount() == 1);
    
    REQUIRE(house.pickItems("fiets", 3) == false);

    REQUIRE(house.pickItems("steen", 7) == true);
    REQUIRE(house.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(house.shelves[0].pallets[3].getItemCount() == 0);
}