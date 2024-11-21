#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& accNum, double bal, const std::string& owner, const std::string& type)
    : accountNumber(accNum), balance(bal), ownerName(owner), accountType(type) {}

std::string BankAccount::getAccountNumber() const { return accountNumber; }
double BankAccount::getBalance() const { return balance; }
std::string BankAccount::getOwnerName() const { return ownerName; }
std::string BankAccount::getAccountType() const { return accountType; }

void BankAccount::setAccountNumber(const std::string& accNum) { accountNumber = accNum; }
void BankAccount::setBalance(double bal) { balance = bal; }
void BankAccount::setOwnerName(const std::string& owner) { ownerName = owner; }
void BankAccount::setAccountType(const std::string& type) { accountType = type; }

std::string BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return "Deposited: " + std::to_string(amount) + ". New Balance: " + std::to_string(balance);
    }
    return "Invalid deposit amount!";
}

std::string BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        return "Invalid withdrawal amount!";
    } else if (amount > balance) {
        return "Insufficient funds!";
    }

    balance -= amount;
    return "Withdrew: " + std::to_string(amount) + ". New Balance: " + std::to_string(balance);
}

std::string BankAccount::displayAccountInfo() const {
    std::ostringstream oss;
    oss << "Account Number: " << accountNumber << "\n"
        << "Owner Name: " << ownerName << "\n"
        << "Account Type: " << accountType << "\n"
        << "Balance: " << balance;
    return oss.str();
}

std::string BankAccount::transfer(BankAccount& toAccount, double amount) {
    if (amount <= 0) {
        return "Invalid transfer amount!";
    }

    if (amount > balance) {
        return "Insufficient funds for transfer!";
    }

    withdraw(amount);
    toAccount.deposit(amount);
    return "Transferred: " + std::to_string(amount) + " to Account " + toAccount.getAccountNumber();
}

bool BankAccount::hasSufficientFunds(double amount) const {
    return amount > 0 && amount <= balance;
}

std::string BankAccount::applyInterest(double interestRate) {
    if (interestRate > 0) {
        double interest = balance * interestRate / 100;
        balance += interest;
        return "Interest applied: " + std::to_string(interest) + ". New Balance: " + std::to_string(balance);
    }
    return "Invalid interest rate!";
}
