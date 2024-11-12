#include "Bank.h"
#include <iostream>

Bank::Bank(std::string name, std::string loc)
    : bankName(name), location(loc) {}

void Bank::addCustomer(Customer customer) {
}

void Bank::removeCustomer(int customerID) {
}

void Bank::getCustomerInfo(int customerID) {
}

void Bank::getBankDetails() {
    std::cout << "Bank: " << bankName << "\nLocation: " << location << std::endl;
}
