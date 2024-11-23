#include "Customer.h"
//The constructor places the attributes defined by their data type along with the attribute of type component that are initialized for further use and definition.
Customer::Customer(std::string customerID, std::string name, std::string phoneNumber, 
                   BankAccount bankAcc, InvestmentAccount investAcc, Card cardType)
    : customerID(customerID), name(name), phoneNumber(phoneNumber), bankAcc(bankAcc), investAcc(investAcc), cardType(cardType) {}
//Paired getters and setters for each attribute to facilitate an organized view of the methods and their return values.
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

std:.string Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::setPhoneNumber(std::string phoneNumber) {
    phoneNumber = phoneNumber;
}
//The following methods include getters and setters that initialize the composition relationships the Customer class has with other 3 classes as a mention of characteristics the class possesses.
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
