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
    // This is the main constructor for the class.
    Bank(const std::string& bankName, const std::string& location);

    // These are the coupled getters and setters for the attributes.
    std::string getBankName() const;
    void setBankName(const std::string& bankName);

    std::string getLocation() const;
    void setLocation(const std::string& location);

    // These additional methods help add, remove, or get the information of a customer.
    Customer getCustomer(const std::string& customerID) const;
    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& customerID);
};

#endif
