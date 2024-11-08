#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int number, double bal, std::string owner, std::string type)
    : accountNumber(number), balance(bal), ownerName(owner), accountType(type) {}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= balance) balance -= amount;
}

void BankAccount::checkBalance() const {
    std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::displayAccountInfo() const {
    std::cout << "Account Number: " << accountNumber 
              << "\nOwner: " << ownerName 
              << "\nAccount Type: " << accountType 
              << "\nBalance: " << balance << std::endl;
}
