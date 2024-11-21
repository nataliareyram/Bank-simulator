#include "Bank.h"
#include <iostream>

Bank::Bank(const std::string& name, const std::string& loc)
    : bankName(name), location(loc) {}

std::string Bank::getBankName() const {
    return bankName;
}

std::string Bank::getLocation() const {
    return location;
}

void Bank::setBankName(const std::string& name) {
    bankName = name;
}

void Bank::setLocation(const std::string& loc) {
    location = loc;
}

void Bank::addCustomer(const Customer& customer) {
    customers.push_back(customer);
    return "Customer " + customer.getName() + " added successfully.";
}

void Bank::removeCustomer(const std::string& customerID) {
    for (size_t i = 0; i < customers.size(); ++i) {
        if (customers[i].getCustomerID() == customerID) {
            customers.erase(customers.begin() + i); 
            return "Customer with ID " + customerID + " removed.";
        }
    }
    return "Customer with ID " + customerID + " not found!";
}

Customer Bank::getCustomerInfo(const std::string& customerID) const {
    for (const auto& customer : customers) {
        if (customer.getCustomerID() == customerID) {
            return customer; 
        }
    }
    throw std::runtime_error("Customer with ID " + customerID + " not found!"); 
}

void Bank::addBankAccount(BankAccount* bankAccount) {
    bankAccounts.push_back(bankAccount);
    return "Bank account added successfully.";
}

void Bank::addInvestmentAccount(InvestmentAccount* investmentAccount) {
    investmentAccounts.push_back(investmentAccount);
    return "Investment account added successfully.";
}
