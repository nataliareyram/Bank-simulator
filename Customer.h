#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"

class Customer {
private:
    std::string customerID;
    std::string name;
    int phoneNumber;
    BankAccount bankAcc;
    InvestmentAccount investAcc;
    Card cardType;

public:
    Customer(const std::string& customerID, const std::string& name, int phoneNumber,
             const BankAccount& bankAcc, const InvestmentAccount& investAcc, const Card& cardType);

    std::string getCustomerID() const;
    void setCustomerID(const std::string& customerID);

    std::string getName() const;
    void setName(const std::string& name);

    int getPhoneNumber() const;
    void setPhoneNumber(int phoneNumber);

    void setBankAccount(const BankAccount& bankAcc);
    void setInvestmentAccount(const InvestmentAccount& investAcc);
    void setCard(const Card& card);
};

#endif // CUSTOMER_H
