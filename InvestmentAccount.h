#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include "BankAccount.h"
//The subclass inherits the methods and attributes of its parent class, having then to establish the ones exclusive to this class.
class InvestmentAccount : public BankAccount {
private:
    double investmentBalance;
    double growthRate;
//The constructor includes the parent class' attributes defined by their data type, as well as the sub class' own attributes and data types.
public:
    InvestmentAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType, 
                      double investmentBalance, double growthRate);
    //The sub class' getters and setters are paired together to organize the program.
    double getInvestmentBalance() const;
    void setInvestmentBalance(double investmentBalance);

    double getGrowthRate() const;
    void setGrowthRate(double growthRate);
    //These methods perform operations on numeric values, but do not get or set information.
    void applyGrowth();
    void transferToInvestment(double amount);
    void withdrawFromInvestment(double amount);
};

#endif
