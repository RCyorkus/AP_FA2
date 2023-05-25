#include "include/employee.hpp"

Employee::Employee(const std::string name, bool forkliftCertificate): name(name), forkliftCertificate(forkliftCertificate){}

std::string Employee::getName(){
    return name;
}