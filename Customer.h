#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"
//Private attributes that belong to the class itself, as well as attributes of type composer that capture classes Customer has a composition relationship with.
class Customer {
private:
    std::string customerID;
    std::string name;
    int phoneNumber;
    BankAccount bankAcc;
    InvestmentAccount investAcc;
    Card cardType;
//The constructor that assigns the data type to the corresponding attribute, as well as the attribute call and definition to the composed classes.
public:
    Customer(std::string customerID, std::string name, int phoneNumber, 
             BankAccount bankAcc, InvestmentAccount investAcc, Card cardType);
    //The paired getters and setters for each attribute.
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
