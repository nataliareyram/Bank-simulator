#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
protected:
    int accountNumber;
    double balance;
    std::string ownerName;
    std::string accountType;

public:
    BankAccount(int number, double bal, std::string owner, std::string type);

    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance() const;
    void displayAccountInfo() const;
};

#endif 
