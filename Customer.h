#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerID;
    std::string name;
    int phoneNumber;

public:
    Customer(std::string id, std::string name, int phone);

    void displayCustomerInfo();
    double getTotalBalance();
};

#endif 
