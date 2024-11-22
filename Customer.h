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
    Customer(std::string customerID, std::string name, int phoneNumber, 
             BankAccount bankAcc, InvestmentAccount investAcc, Card cardType);

    std::string getCustomerID() const;
    void setCustomerID(std::string customerID);

    std::string getName() const;
    void setName(std::string name);

    int getPhoneNumber() const;
    void setPhoneNumber(int phoneNumber);

    BankAccount getBankAccount() const;
    void setBankAccount(BankAccount bankAcc);

    InvestmentAccount getInvestmentAccount() const;
    void setInvestmentAccount(InvestmentAccount investAcc);

    Card getCard() const;
    void setCard(Card cardType);
};

#endif
