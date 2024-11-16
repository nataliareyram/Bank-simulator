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
    BankAccount(const std::string& accNum, double bal, const std::string& owner, const std::string& type);

    std::string getAccountNumber() const;
    double getBalance() const;
    std::string getOwnerName() const;
    std::string getAccountType() const;

    void setAccountNumber(const std::string& accNum);
    void setBalance(double bal);
    void setOwnerName(const std::string& owner);
    void setAccountType(const std::string& type);

    void deposit(double amount);
    void withdraw(double amount);
    std::string displayAccountInfo() const;
};

#endif // BANKACCOUNT_H
