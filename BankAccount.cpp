#include "BankAccount.h"
#include <stdexcept>

BankAccount::BankAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType)
    : accountNumber(accountNumber), balance(balance), ownerName(ownerName), accountType(accountType) {}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::setAccountNumber(std::string accountNumber) {
    accountNumber = accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    balance = balance;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::setOwnerName(std::string ownerName) {
    ownerName = ownerName;
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

void BankAccount::setAccountType(std::string accountType) {
    accountType = accountType;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        throw std::runtime_error("Insufficient funds");
    }
}
