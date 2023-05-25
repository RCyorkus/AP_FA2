#pragma once

#include <iostream>
#include <vector>

#include "shelf.hpp"
#include "employee.hpp"

class Warehouse{
    public:
        std::vector<Employee> Employees;
        std::vector<Shelf> shelves;

    Warehouse();

    void addEmployee(Employee employee);

    void addShelf(Shelf shelf);

    bool rearrangeShelf(Shelf& shelf);

    bool pickItems(const std::string& itemName, int itemCount);
};