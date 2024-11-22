#include "Customer.h"

Customer::Customer(const std::string& customerID, const std::string& name, int phoneNumber,
                   const BankAccount& bankAcc, const InvestmentAccount& investAcc, const Card& cardType)
    : customerID(customerID), name(name), phoneNumber(phoneNumber),
      bankAcc(bankAcc), investAcc(investAcc), cardType(cardType) {}

std::string Customer::getCustomerID() const {
    return customerID;
}

void Customer::setCustomerID(const std::string& customerID) {
    this->customerID = customerID;
}

std::string Customer::getName() const {
    return name;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

int Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::setPhoneNumber(int phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::setBankAccount(const BankAccount& bankAcc) {
    this->bankAcc = bankAcc;
}

void Customer::setInvestmentAccount(const InvestmentAccount& investAcc) {
    this->investAcc = investAcc;
}

void Customer::setCard(const Card& card) {
    this->cardType = card;
}
