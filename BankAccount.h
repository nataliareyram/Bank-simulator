#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string ownerName;
    std::string accountType;

public:
    BankAccount(const std::string& accountNumber, double balance, const std::string& ownerName, const std::string& accountType);

    std::string getAccountNumber() const;
    void setAccountNumber(const std::string& accountNumber);

    double getBalance() const;
    void setBalance(double balance);

    std::string getOwnerName() const;
    void setOwnerName(const std::string& ownerName);

    std::string getAccountType() const;
    void setAccountType(const std::string& accountType);

    void deposit(double amount);
    void withdraw(double amount);
};

#endif // BANKACCOUNT_H
