#include "Customer.h"

Customer::Customer(std::string customerID, std::string name, int phoneNumber, 
                   BankAccount bankAcc, InvestmentAccount investAcc, Card cardType)
    : customerID(customerID), name(name), phoneNumber(phoneNumber), bankAcc(bankAcc), investAcc(investAcc), cardType(cardType) {}

std::string Customer::getCustomerID() const {
    return customerID;
}

void Customer::setCustomerID(std::string customerID) {
    customerID = customerID;
}

std::string Customer::getName() const {
    return name;
}

void Customer::setName(std::string name) {
    name = name;
}

int Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::setPhoneNumber(int phoneNumber) {
    phoneNumber = phoneNumber;
}

BankAccount Customer::getBankAccount() const {
    return bankAcc;
}

void Customer::setBankAccount(BankAccount bankAcc) {
    bankAcc = bankAcc;
}

InvestmentAccount Customer::getInvestmentAccount() const {
    return investAcc;
}

void Customer::setInvestmentAccount(InvestmentAccount investAcc) {
    investAcc = investAcc;
}

Card Customer::getCard() const {
    return cardType;
}

void Customer::setCard(Card cardType) {
    cardType = cardType;
}
