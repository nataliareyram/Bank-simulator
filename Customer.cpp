#include "Customer.h"

Customer::Customer(const std::string& id, const std::string& customerName, int phone)
    : customerID(id), name(customerName), phoneNumber(phone) {}

std::string Customer::getCustomerID() const {
    return customerID;
}

std::string Customer::getName() const {
    return name;
}

int Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::setCustomerID(const std::string& id) {
    customerID = id;
}

void Customer::setName(const std::string& customerName) {
    name = customerName;
}

void Customer::setPhoneNumber(int phone) {
    phoneNumber = phone;
}
