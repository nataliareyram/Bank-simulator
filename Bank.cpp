#include "Bank.h"
#include <algorithm>
#include <stdexcept>
//Main class constructor that gathers the corresponding attributes and methods along with their data type.
Bank::Bank(std::string bankName, std::string location) 
    : bankName(bankName), location(location) {}
//Getters and setters are paired in order to have an organized view of the methods and their return values.
std::string Bank::getBankName() const {
    return bankName;
}

void Bank::setBankName(std::string bankName) {
    bankName = bankName;
}

std::string Bank::getLocation() const {
    return location;
}

void Bank::setLocation(std::string location) {
    location = location;
}

Customer Bank::getCustomer(std::string customerID) const {
    for (const auto& customer : customers) {
        if (customer.getCustomerID() == customerID) {
            return customer;
        }
    }
    throw std::runtime_error("Customer not found");
}

void Bank::addCustomer(Customer customer) {
    customers.push_back(customer);
}

void Bank::removeCustomer(std::string customerID) {
    customers.erase(std::remove_if(customers.begin(), customers.end(), 
        [&customerID](Customer& c) {
            return c.getCustomerID() == customerID;
        }), customers.end());
}
