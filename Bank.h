#ifndef BANK_H
#define BANK_H

#include <string>
#include "Customer.h"

class Bank {
private:
    std::string bankName;
    std::string location;

public:
    Bank(std::string name, std::string loc);

    void addCustomer(Customer customer);
    void removeCustomer(int customerID);
    void getCustomerInfo(int customerID);
    void getBankDetails();
};
