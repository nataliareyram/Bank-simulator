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
    Bank(const std::string& bankName, const std::string& location);

    std::string getBankName() const;
    void setBankName(const std::string& bankName);

    std::string getLocation() const;
    void setLocation(const std::string& location);

    Customer getCustomer(const std::string& customerID) const;
    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& customerID);
};

#endif // BANK_H
