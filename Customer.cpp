#include "Customer.h"
#include <iostream>

Customer::Customer(std::string id, std::string name, int phone)
    : customerID(id), name(name), phoneNumber(phone) {}

void Customer::displayCustomerInfo() {
    std::cout << "ID: " << customerID << "\nName: " << name 
              << "\nPhone: " << phoneNumber << std::endl;
}

double Customer::getTotalBalance() {
    return 0.0; 
}
