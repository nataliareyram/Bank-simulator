#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerID;
    std::string name;
    int phoneNumber;

public:
    Customer(const std::string& customerID, const std::string& name, int phoneNumber);

    std::string getCustomerID() const;
    std::string getName() const;
    int getPhoneNumber() const;

    void setCustomerID(const std::string& customerID);
    void setName(const std::string& name);
    void setPhoneNumber(int phoneNumber);
};

#endif // CUSTOMER_H
