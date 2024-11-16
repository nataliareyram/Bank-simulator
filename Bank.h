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
    Bank(const std::string& name, const std::string& loc);

    std::string getBankName() const;
    std::string getLocation() const;

    void setBankName(const std::string& name);
    void setLocation(const std::string& loc);

    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& customerID);
    Customer getCustomerInfo(const std::string& customerID) const;
};

#endif // BANK_H
