#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
//Protected attributes along with their data tyoes
class BankAccount {
protected:
    std::string accountNumber;
    double balance;
    std::string ownerName;
    std::string accountType;
//Main constructor that includes the aforementioned attributes defined by their data type.
public:
    BankAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType);
    //Getters and setters are paired by method to keep an organized process.
    std::string getAccountNumber() const;
    void setAccountNumber(std::string accountNumber);

    double getBalance() const;
    void setBalance(double balance);

    std::string getOwnerName() const;
    void setOwnerName(std::string ownerName);

    std::string getAccountType() const;
    void setAccountType(std::string accountType);
    //These two independent methods are meant to perform operations, not get or set information.
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
