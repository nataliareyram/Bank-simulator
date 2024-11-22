#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Customer.h"

class Bank {
private:
    std::string bankName;
    std::string location;
    std::vector<Customer> customers; 

public:
    // These is the main constructor for the class.
    Bank(const std::string& name, const std::string& loc);

    // These are the getters for the Bank name and location.
    std::string getBankName() const;
    std::string getLocation() const;

    // These are the setters for Bank name and location.
    void setBankName(const std::string& name);
    void setLocation(const std::string& loc);

    // These additional methods help add, remove, or get the information of a customer.
    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& customerID);
    Customer getCustomer(const std::string& customerID) const;
};

#endif

