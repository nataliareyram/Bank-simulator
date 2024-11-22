#include "BankAccount.h"

BankAccount::BankAccount(const std::string& accountNumber, double balance, const std::string& ownerName, const std::string& accountType)
    : accountNumber(accountNumber), balance(balance), ownerName(ownerName), accountType(accountType) {}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::setAccountNumber(const std::string& accountNumber) {
    this->accountNumber = accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::setOwnerName(const std::string& ownerName) {
    this->ownerName = ownerName;
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

void BankAccount::setAccountType(const std::string& accountType) {
    this->accountType = accountType;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
}
