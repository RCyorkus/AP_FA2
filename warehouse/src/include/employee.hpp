#pragma once

#include <iostream>

class Employee{
    private:
        const std::string name;
    
    public:
        bool busy;
        bool forkliftCertificate;


    Employee(std::string name, bool forkliftCertificate);

    std::string getName();
};