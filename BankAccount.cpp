#include "BankAccount.h"
#include <iostream> 

BankAccount::BankAccount(const std::string& accNum, double bal, const std::string& owner, const std::string& type)
    : accountNumber(accNum), balance(bal), ownerName(owner), accountType(type) {}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

void BankAccount::setAccountNumber(const std::string& accNum) {
    accountNumber = accNum;
}

void BankAccount::setBalance(double bal) {
    balance = bal;
}

void BankAccount::setOwnerName(const std::string& owner) {
    ownerName = owner;
}

void BankAccount::setAccountType(const std::string& type) {
    accountType = type;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited: " << amount << ". New Balance: " << balance << std::endl;
    } else {
        std::cout << "Invalid deposit amount!" << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew: " << amount << ". New Balance: " << balance << std::endl;
    } else if (amount > balance) {
        std::cout << "Insufficient funds!" << std::endl;
    } else {
        std::cout << "Invalid withdrawal amount!" << std::endl;
    }
}

std::string BankAccount::displayAccountInfo() const {
    return "Account Number: " + accountNumber + "\n" +
           "Owner Name: " + ownerName + "\n" +
           "Account Type: " + accountType + "\n" +
           "Balance: " + std::to_string(balance);
}
